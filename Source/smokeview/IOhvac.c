#include "options.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include GLUT_H
#include <math.h>

#include "smokeviewvars.h"
#include "IOobjects.h"

unsigned char hvac_off_color[3] = {0, 255, 0}, hvac_on_color[3] = {255, 0, 0};
unsigned char *hvac_color_states[2] = {hvac_off_color, hvac_on_color};

/* ------------------ SetMetroPaths ------------------------ */

void SetMetroPaths(void){
  int i;

  for(i = 0;i < nhvacductinfo;i++){
    int j;
    hvacductdata *ducti;
    hvacnodedata *from_i, *to_i;
    float *xyz_from;
    float *xyz_to;

    ducti  = hvacductinfo + i;
    from_i = ducti->node_from;
    to_i   = ducti->node_to;
    if(from_i == NULL || to_i == NULL)continue;
    xyz_from = from_i->xyz;
    xyz_to   = to_i->xyz;
    for(j = 0;j < nhvacductinfo;j++){
      hvacductdata *ductj;
      hvacnodedata *from_j, *to_j;
      float diff[3];

      if(i == j)continue;
      ductj = hvacductinfo + j;
      from_j = ductj->node_from;
      to_j   = ductj->node_to;
      if(from_j == NULL || to_j == NULL)continue;
      if(from_i != from_j && from_i != to_j && to_i != from_j && to_i != to_j)continue;
      diff[0] = ABS(xyz_from[0] - xyz_to[0]);
      diff[1] = ABS(xyz_from[1] - xyz_to[1]);
      diff[2] = ABS(xyz_from[2] - xyz_to[2]);
      if(diff[0] < MIN(diff[1], diff[2])){
        ducti->metro_path = DUCT_YZX;
        ductj->metro_path = DUCT_ZYX;
      }
      else if(diff[1] < MIN(diff[0], diff[2])){
        ducti->metro_path = DUCT_XZY;
        ductj->metro_path = DUCT_ZXY;
      }
      else{
        ducti->metro_path = DUCT_XYZ;
        ductj->metro_path = DUCT_YXZ;
      }
    }
  }
#define COPYVALS3(xyz, x, y, z) \
  xyz[0] = (x);\
  xyz[1] = (y);\
  xyz[2] = (z)
  for(i=0;i<nhvacductinfo;i++){
    hvacductdata *ducti;
    hvacnodedata *node_from, *node_to;
    float *xyz0, *xyz1;

    ducti = hvacductinfo + i;
    node_from = hvacnodeinfo + ducti->node_id_from;
    node_to = hvacnodeinfo + ducti->node_id_to;
    if(node_from == NULL || node_to == NULL)continue;
    xyz0 = node_from->xyz;
    xyz1 = node_to->xyz;
    float *dxyz, *dxyz_metro;
    dxyz = ducti->normal;
    dxyz_metro = ducti->normal_metro;
    dxyz[0] = xyz1[0] - xyz0[0];
    dxyz[1] = xyz1[1] - xyz0[1];
    dxyz[2] = xyz1[2] - xyz0[2];
    dxyz_metro[0] = 0.0;
    dxyz_metro[1] = 0.0;
    dxyz_metro[2] = 0.0;
    memcpy(ducti->xyz_symbol_metro, xyz0, 3 * sizeof(float));
    memcpy(ducti->xyz_label_metro,  xyz0, 3 * sizeof(float));
    switch(ducti->metro_path){
      case DUCT_XYZ:
        COPYVALS3(ducti->xyz_metro1, xyz1[0], xyz0[1], xyz0[2]);
        COPYVALS3(ducti->xyz_metro2, xyz1[0], xyz0[1], xyz0[2]);
        COPYVALS3(ducti->xyz_metro3, xyz1[0], xyz1[1], xyz0[2]);
        COPYVALS3(ducti->xyz_metro4, xyz1[0], xyz1[1], xyz0[2]);
        if(ABS(dxyz[0]) > ABS(dxyz[1])){
          ducti->xyz_symbol_metro[0] += 0.5*dxyz[0];
          ducti->xyz_label_metro[0]  += 0.75*dxyz[0];
          dxyz_metro[0] = 1.0;
        }
        else{
          ducti->xyz_symbol_metro[0] += dxyz[0];
          ducti->xyz_symbol_metro[1] += 0.5*dxyz[1];
          ducti->xyz_label_metro[0] += dxyz[0];
          ducti->xyz_label_metro[1] += 0.75*dxyz[1];
          dxyz_metro[1] = 1.0;
        }
        break;
      case DUCT_XZY:
        COPYVALS3(ducti->xyz_metro1, xyz1[0], xyz0[1], xyz0[2]);
        COPYVALS3(ducti->xyz_metro2, xyz1[0], xyz0[1], xyz0[2]);
        COPYVALS3(ducti->xyz_metro3, xyz1[0], xyz0[1], xyz1[2]);
        COPYVALS3(ducti->xyz_metro4, xyz1[0], xyz0[1], xyz1[2]);
        if(ABS(dxyz[0]) > ABS(dxyz[2])){
          ducti->xyz_symbol_metro[0] += 0.50*dxyz[0];
          ducti->xyz_label_metro[0]  += 0.75*dxyz[0];
          dxyz_metro[0] = 1.0;
        }
        else{
          ducti->xyz_symbol_metro[0] += dxyz[0];
          ducti->xyz_symbol_metro[2] += 0.5*dxyz[2];
          ducti->xyz_label_metro[0]  += dxyz[0];
          ducti->xyz_label_metro[2]  += 0.75*dxyz[2];
          dxyz_metro[2] = 1.0;
        }
        break;
      case DUCT_YXZ:
        COPYVALS3(ducti->xyz_metro1, xyz0[0], xyz1[1], xyz0[2]);
        COPYVALS3(ducti->xyz_metro2, xyz0[0], xyz1[1], xyz0[2]);
        COPYVALS3(ducti->xyz_metro3, xyz1[0], xyz1[1], xyz0[2]);
        COPYVALS3(ducti->xyz_metro4, xyz1[0], xyz1[1], xyz0[2]);
        if(ABS(dxyz[1]) > ABS(dxyz[0])){
          ducti->xyz_symbol_metro[1] += 0.50*dxyz[1];
          ducti->xyz_label_metro[1]  += 0.75*dxyz[1];
          dxyz_metro[1] = 1.0;
        }
        else{
          ducti->xyz_symbol_metro[0] += 0.50*dxyz[0];
          ducti->xyz_symbol_metro[1] += dxyz[1];
          ducti->xyz_label_metro[0]  += 0.75*dxyz[0];
          ducti->xyz_label_metro[1]  += dxyz[1];
          dxyz_metro[0] = 1.0;
        }
        break;
      case DUCT_YZX:
        COPYVALS3(ducti->xyz_metro1, xyz0[0], xyz1[1], xyz0[2]);
        COPYVALS3(ducti->xyz_metro2, xyz0[0], xyz1[1], xyz0[2]);
        COPYVALS3(ducti->xyz_metro3, xyz0[0], xyz1[1], xyz1[2]);
        COPYVALS3(ducti->xyz_metro4, xyz0[0], xyz1[1], xyz1[2]);
        if(ABS(dxyz[1]) > ABS(dxyz[2])){
          ducti->xyz_symbol_metro[1] += 0.50*dxyz[1];
          ducti->xyz_label_metro[1]  += 0.75*dxyz[1];
          dxyz_metro[1] = 1.0;
        }
        else{
          ducti->xyz_symbol_metro[1] += dxyz[1];
          ducti->xyz_symbol_metro[2] += 0.50*dxyz[2];
          ducti->xyz_label_metro[1]  += dxyz[1];
          ducti->xyz_label_metro[2]  += 0.75*dxyz[2];
          dxyz_metro[2] = 1.0;
        }
        break;
      case DUCT_ZXY:
        COPYVALS3(ducti->xyz_metro1, xyz0[0], xyz0[1], xyz1[2]);
        COPYVALS3(ducti->xyz_metro2, xyz0[0], xyz0[1], xyz1[2]);
        COPYVALS3(ducti->xyz_metro3, xyz1[0], xyz0[1], xyz1[2]);
        COPYVALS3(ducti->xyz_metro4, xyz1[0], xyz0[1], xyz1[2]);
        if(ABS(dxyz[2]) > ABS(dxyz[0])){
          ducti->xyz_symbol_metro[2] += 0.50*dxyz[2];
          ducti->xyz_label_metro[2]  += 0.75*dxyz[2];
          dxyz_metro[2] = 1.0;
        }
        else{
          ducti->xyz_symbol_metro[0] += 0.50*dxyz[0];
          ducti->xyz_symbol_metro[2] += dxyz[2];
          ducti->xyz_label_metro[0] += 0.75 * dxyz[0];
          ducti->xyz_label_metro[2] += dxyz[2];
          dxyz_metro[0] = 1.0;
        }
        break;
      case DUCT_ZYX:
        COPYVALS3(ducti->xyz_metro1, xyz0[0], xyz0[1], xyz1[2]);
        COPYVALS3(ducti->xyz_metro2, xyz0[0], xyz0[1], xyz1[2]);
        COPYVALS3(ducti->xyz_metro3, xyz0[0], xyz1[1], xyz1[2]);
        COPYVALS3(ducti->xyz_metro4, xyz0[0], xyz1[1], xyz1[2]);
        if(ABS(dxyz[2]) > ABS(dxyz[1])){
          ducti->xyz_symbol_metro[2] += 0.50*dxyz[2];
          ducti->xyz_label_metro[2]  += 0.75 * dxyz[2];
          dxyz_metro[2] = 1.0;
        }
        else{
          ducti->xyz_symbol_metro[1] += 0.50*dxyz[1];
          ducti->xyz_symbol_metro[2] += dxyz[2];
          ducti->xyz_label_metro[1] += 0.75 * dxyz[1];
          ducti->xyz_label_metro[2] += dxyz[2];
          dxyz_metro[1] = 1.0;
        }
      default:
        ASSERT(FFALSE);
        break;
    }
  }
}

/* ------------------ GetHVACState ------------------------ */

int GetHVACDuctState(hvacductdata *ducti){
  int i, n, *states;
  float *times;
  float current_time;

  if(global_times==NULL)return HVAC_STATE_INACTIVE;
  times = ducti->act_times;
  states = ducti->act_states;
  n = ducti->nact_times;
  if(n==0||times==NULL)return HVAC_STATE_INACTIVE;

  current_time = GetTime();

  if(current_time < times[0])return HVAC_STATE_INACTIVE;
  for(i = 0;i < n - 1;i++){
    if(current_time >= times[i] && current_time < times[i + 1])return states[i];
  }
  return states[n - 1];
}

/* ------------------ GetDuctDir ------------------------ */

int GetDuctDir(float *xyz){
  float eyedir[3];

  //cos(angle) = dir1 .dot. dir2 /(norm(dir1)*norm(dir2))
  eyedir[0] = ABS(xyz[0] - fds_eyepos[0]);
  eyedir[1] = ABS(xyz[1] - fds_eyepos[1]);
  eyedir[2] = ABS(xyz[2] - fds_eyepos[2]);
  if(eyedir[0]>MAX(eyedir[1],eyedir[2]))return 1;
  if(eyedir[1]>MAX(eyedir[0],eyedir[2]))return 0;
  return 2;
}

/* ------------------ DrawHVACDamper ------------------------ */

void DrawHVACDamper(hvacductdata *ducti, float *xyz, float diam, int state){
  float cyl_diam, cyl_height;
  unsigned char color2[3] = {0, 0, 0};
  unsigned char *color;
  float axis[3];
  float u[3] = {0.0, 0.0, 1.0}, *v, angle;

  color = hvac_color_states[state];
  color2[0] = CLAMP(255 * foregroundcolor[0], 0, 255);
  color2[1] = CLAMP(255 * foregroundcolor[1], 0, 255);
  color2[2] = CLAMP(255 * foregroundcolor[2], 0, 255);

  cyl_diam = diam / 4.0;
  cyl_height = 3.0 * diam;
  glPushMatrix();
  glTranslatef(xyz[0], xyz[1], xyz[2]);
  DrawSphere(diam, color);

  if(hvac_metro_view == 1){
    v = ducti->normal_metro;
  }
  else{
    v = ducti->normal;
  }

  RotateU2V(u, v, axis, &angle);
  angle *= 180.0 / 3.14159;
  if(state == 0){
    glRotatef(-45.0, 0.0, 1.0, 0.0);
  }
  else{
    glRotatef(-90.0, 0.0, 1.0, 0.0);
  }

  glRotatef(angle, axis[0], axis[1], axis[2]);

  glTranslatef(0.0, 0.0, -cyl_height/2.0);
  DrawDisk(cyl_diam, cyl_height, color2);
  glPopMatrix();
}

/* ------------------ DrawHVACAircoil ------------------------ */

void DrawHVACAircoil(hvacductdata *ducti, float *xyz, float size, float diam, int state){
  unsigned char *color;
  float axis[3];
  float u[3] = {1.0, 0.0, 0.0}, *v, angle;

  color = hvac_color_states[state];

  glPushMatrix();
  glTranslatef(xyz[0], xyz[1], xyz[2]);
  DrawSphere(diam, color);

  if(hvac_metro_view == 1){
    v = ducti->normal_metro;
  }
  else{
    v = ducti->normal;
  }
  RotateU2V(u, v, axis, &angle);
  angle *= 180.0 / 3.14159;
  glRotatef(angle, axis[0], axis[1], axis[2]);

  glLineWidth(2.0);
  glColor3fv(foregroundcolor);
  glScalef(size, size, size);
  glBegin(GL_LINES);
  glVertex3f(-1.0,  0.0,  0.0);
  glVertex3f(-0.75, 0.0, -0.5);

  glVertex3f(-0.75, 0.0, -0.5);
  glVertex3f(-0.25, 0.0,  0.5);

  glVertex3f(-0.25, 0.0,  0.5);
  glVertex3f( 0.25, 0.0, -0.5);

  glVertex3f(0.25, 0.0, -0.5);
  glVertex3f(0.75, 0.0,  0.5);

  glVertex3f(0.75, 0.0, 0.5);
  glVertex3f(1.0 , 0.0, 0.0);
  glEnd();
  glPopMatrix();
}

/* ------------------ DrawHVACFan ------------------------ */

void DrawHVACFan(hvacductdata *ducti, float *xyz, float size, float diam, int state){
  int i;
  unsigned char *color;
  float axis[3];
  float u[3] = {1.0, 0.0, 0.0}, *v, angle;

  color = hvac_color_states[state];
  if(hvac_circ_x == NULL||hvac_circ_y==NULL){
    FREEMEMORY(hvac_circ_x);
    FREEMEMORY(hvac_circ_y);
    NewMemory((void **)&hvac_circ_x,2*HVAC_NCIRC*sizeof(float));
    NewMemory((void **)&hvac_circ_y,2*HVAC_NCIRC*sizeof(float));
    for(i=0;i<HVAC_NCIRC;i++){
      float arg;
      float r, xx, yy;

      arg = 2.0*PI*(float)i/(float)(HVAC_NCIRC-1);
      hvac_circ_x[i] = cos(arg);
      hvac_circ_y[i] = sin(arg);
      r = sin(2.0 * arg);
      xx = r * cos(arg);
      yy = r * sin(arg);
      hvac_circ_x[i + HVAC_NCIRC] = xx;
      hvac_circ_y[i + HVAC_NCIRC] = yy;
    }
  }
  glPushMatrix();
  glTranslatef(xyz[0], xyz[1], xyz[2]);
  DrawSphere(diam, color);
  glLineWidth(2.0);

  if(hvac_metro_view == 1){
    v = ducti->normal_metro;
  }
  else{
    v = ducti->normal;
  }
  RotateU2V(u, v, axis, &angle);
  angle *= 180.0 / 3.14159;
  glRotatef(angle, axis[0], axis[1], axis[2]);
  glRotatef(90, 0.0,0.0,1.0);
  if(state==1&&global_times != NULL){
    float angle2, time2;

    time2 = global_times[itimes];
    angle2 = 360.0*time2 / 10.0;
    glRotatef(angle2, 0.0, 1.0, 0.0);
  }

  glScalef(size,size,size);
  glColor3fv(foregroundcolor);
  glBegin(GL_LINES);
  for(i=0;i<2*HVAC_NCIRC-1;i++){
    float x, y, xp1, yp1;

    if(i == HVAC_NCIRC - 1)continue;
    x   = hvac_circ_x[i];
    xp1 = hvac_circ_x[i+1];
    y   = hvac_circ_y[i];
    yp1 = hvac_circ_y[i+1];
    glVertex3f(x,   0.0, y);
    glVertex3f(xp1, 0.0, yp1);
  }
  glEnd();
  glPopMatrix();
}

/* ------------------ DrawHVACFilter ------------------------ */

void DrawHVACFilter(hvacductdata *ducti, float *xyz, float size){
  float axis[3];
  float u[3] = {0.0, 1.0, 0.0}, *v, angle;

  glPushMatrix();
  glTranslatef(xyz[0], xyz[1], xyz[2]);
  if(ducti!=NULL){
    if(hvac_metro_view == 1){
      v = ducti->normal_metro;
    }
    else{
      v = ducti->normal;
    }
    RotateU2V(u, v, axis, &angle);
    angle *= 180.0 / 3.14159;
    glRotatef(angle, axis[0], axis[1], axis[2]);
  }
  glRotatef(90.0, 0.0, 0.0, 1.0);
  glLineWidth(2.0);
  glScalef(size,size,size);
  glBegin(GL_LINES);
  glVertex3f(0.0, -0.5, -1.0);
  glVertex3f(0.0,  0.5, -1.0);

  glVertex3f(0.0, -0.5, -0.5);
  glVertex3f(0.0,  0.5, -0.5);

  glVertex3f(0.0, -0.5,  0.0);
  glVertex3f(0.0,  0.5,  0.0);

  glVertex3f(0.0, -0.5,  0.5);
  glVertex3f(0.0,  0.5,  0.5);

  glVertex3f(0.0, -0.5,  1.0);
  glVertex3f(0.0,  0.5,  1.0);

  glVertex3f(0.0, -0.5, -1.0);
  glVertex3f(0.0, -0.5,  1.0);
  
  glVertex3f(0.0,  0.5, -1.0);
  glVertex3f(0.0,  0.5,  1.0);
  glEnd();
  glPopMatrix();
}

/* ------------------ GetHVACDuctID ------------------------ */

hvacductdata *GetHVACDuctID(char *duct_name){
  int i;

  for(i = 0;i < nhvacductinfo;i++){
    hvacductdata *ducti;

    ducti = hvacductinfo + i;
    if(strcmp(ducti->duct_name, duct_name) == 0)return ducti;
  }
  return NULL;
}

/* ------------------ GetHVACNodeID ------------------------ */

hvacnodedata *GetHVACNodeID(char *node_name){
  int i;

  for(i = 0;i < nhvacnodeinfo;i++){
    hvacnodedata *nodei;

    nodei = hvacnodeinfo + i;
    if(strcmp(nodei->duct_name, node_name) == 0)return nodei;
  }
  return NULL;
}

/* ------------------ DrawHVAC ------------------------ */

void DrawHVAC(hvacdata *hvaci){
  int i;
  unsigned char uc_color[3];

  glPushMatrix();
  glScalef(SCALE2SMV(1.0), SCALE2SMV(1.0), SCALE2SMV(1.0));
  glTranslatef(-xbar0, -ybar0, -zbar0);

  // draw ducts
  
  glLineWidth(hvaci->duct_width);
  glBegin(GL_LINES);
  uc_color[0] = CLAMP(hvaci->duct_color[0], 0, 255);
  uc_color[1] = CLAMP(hvaci->duct_color[1], 0, 255);
  uc_color[2] = CLAMP(hvaci->duct_color[2], 0, 255);
  glColor3ubv(uc_color);
  for(i = 0; i < nhvacductinfo; i++){
    hvacductdata *ducti;
    hvacnodedata *node_from, *node_to;
    float *xyz0, *xyz1;

    ducti = hvacductinfo + i;
    if(strcmp(hvaci->network_name, ducti->network_name) != 0)continue;

    node_from = hvacnodeinfo + ducti->node_id_from;
    node_to = hvacnodeinfo + ducti->node_id_to;
    if(node_from == NULL || node_to == NULL)continue;
    xyz0 = node_from->xyz;
    xyz1 = node_to->xyz;
    glVertex3fv(xyz0);
    if(hvac_metro_view == 1){
      glVertex3fv(ducti->xyz_metro1);
      glVertex3fv(ducti->xyz_metro2);
      glVertex3fv(ducti->xyz_metro3);
      glVertex3fv(ducti->xyz_metro4);
    }
    glVertex3fv(xyz1);
  }
  glEnd();
  SNIFF_ERRORS("after hvac network");
  if(hvaci->show_duct_labels == 1){
    for(i = 0; i < nhvacductinfo; i++){
      hvacductdata *ducti;
      hvacnodedata *node_from, *node_to;
      float xyz[3];
      char label[256];
      float offset;

      ducti = hvacductinfo + i;
      if(strcmp(hvaci->network_name, ducti->network_name) != 0)continue;

      strcpy(label, ducti->duct_name);
      node_from = hvacnodeinfo + ducti->node_id_from;
      node_to   = hvacnodeinfo + ducti->node_id_to;
      if(node_from == NULL || node_to == NULL)continue;
      if(hvac_metro_view==1){
        memcpy(xyz, ducti->xyz_label_metro, 3 * sizeof(float));
      }
      else{
        memcpy(xyz, ducti->xyz_label, 3 * sizeof(float));
      }
      offset = 0.01/xyzmaxdiff;
      Output3Text(foregroundcolor, xyz[0]+offset, xyz[1]+offset, xyz[2]+offset, label);
    }
  }
  if(hvaci->show_component == DUCT_COMPONENT_TEXT){
    for(i = 0; i < nhvacductinfo; i++){
      hvacductdata *ducti;
      hvacnodedata *node_from, *node_to;
      float xyz[3];
      char label[256];

      ducti = hvacductinfo + i;
      if(strcmp(hvaci->network_name, ducti->network_name) != 0)continue;

      strcpy(label, "");
      strcat(label, ducti->c_component);
      node_from = hvacnodeinfo + ducti->node_id_from;
      node_to   = hvacnodeinfo + ducti->node_id_to;
      if(node_from == NULL || node_to == NULL)continue;
      if(hvac_metro_view == 1){
        memcpy(xyz, ducti->xyz_symbol_metro, 3 * sizeof(float));
      }
      else{
        memcpy(xyz, ducti->xyz_symbol, 3 * sizeof(float));
      }
      xyz[2] += 0.01 / xyzmaxdiff;
      Output3Text(foregroundcolor, xyz[0], xyz[1], xyz[2]+0.01/xyzmaxdiff, label);
    }
  }
  if(hvaci->show_component == DUCT_COMPONENT_SYMBOLS){
    for(i = 0; i < nhvacductinfo; i++){
      hvacductdata *ducti;
      hvacnodedata *node_from, *node_to;
      float *xyz;

      ducti = hvacductinfo + i;
      if(strcmp(hvaci->network_name, ducti->network_name) != 0)continue;
      node_from = hvacnodeinfo + ducti->node_id_from;
      node_to   = hvacnodeinfo + ducti->node_id_to;
      if(node_from == NULL || node_to == NULL)continue;
      float size;
      int state;

      state = GetHVACDuctState(ducti);
      size = xyzmaxdiff / 40.0;
      size *= hvaci->duct_size;
      if(hvac_metro_view == 1){
        xyz = ducti->xyz_symbol_metro;
      }
      else{
        xyz = ducti->xyz_symbol;
      }
      switch(ducti->component){
      case HVAC_NONE:
        break;
      case HVAC_FAN:
        DrawHVACFan(ducti, xyz, 0.75*2.0*size, 0.75*size, state);
        break;
      case HVAC_AIRCOIL:
        DrawHVACAircoil(ducti, xyz, 2.0*size, size, state);
        break;
      case HVAC_DAMPER:
        DrawHVACDamper(ducti, xyz, size, state);
        break;
      default:
        ASSERT(FFALSE);
        break;
      }
    }
  }

  // draw nodes
  glPointSize(hvaci->node_size);
  glBegin(GL_POINTS);
  uc_color[0] = CLAMP(hvaci->node_color[0], 0, 255);
  uc_color[1] = CLAMP(hvaci->node_color[1], 0, 255);
  uc_color[2] = CLAMP(hvaci->node_color[2], 0, 255);
  glColor3ubv(uc_color);
  for(i = 0; i < nhvacnodeinfo; i++){
    hvacnodedata *nodei;

    nodei = hvacnodeinfo + i;
    if(strcmp(hvaci->network_name, nodei->network_name) != 0)continue;

    glVertex3fv(nodei->xyz);
  }
  glEnd();

  if(hvaci->show_node_labels == 1){
    for(i = 0; i < nhvacnodeinfo; i++){
      hvacnodedata* nodei;
      char label[256];
      float offset;

      nodei = hvacnodeinfo + i;
      if(strcmp(hvaci->network_name, nodei->network_name) != 0)continue;
      offset = 0.01/xyzmaxdiff;
      strcpy(label, nodei->node_name);
      Output3Text(foregroundcolor, nodei->xyz[0]+offset, nodei->xyz[1]+offset, nodei->xyz[2]+offset, label);
    }
  }
  if(hvaci->show_filters == NODE_INFO_LABELS){
    for(i = 0; i < nhvacnodeinfo; i++){
      hvacnodedata *nodei;
      char label[256];
      float offset;

      nodei = hvacnodeinfo + i;
      if(strcmp(hvaci->network_name, nodei->network_name) != 0)continue;
      strcpy(label, nodei->c_filter);
      offset = 0.01 / xyzmaxdiff;
      Output3Text(foregroundcolor, nodei->xyz[0]+offset, nodei->xyz[1] + offset, nodei->xyz[2] + offset, label);
    }
  }
  if(hvaci->show_filters == NODE_INFO_SYMBOLS){
    for(i = 0; i < nhvacnodeinfo; i++){
      hvacnodedata *nodei;
      float size;

      size = xyzmaxdiff / 25.0;
      size *= hvaci->duct_size;
      nodei = hvacnodeinfo + i;
      if(strcmp(hvaci->network_name, nodei->network_name) != 0)continue;
      if(nodei->filter == HVAC_FILTER_NO)continue;
      DrawHVACFilter(nodei->duct, nodei->xyz, size);
    }
  }

  glPopMatrix();
}

/* ------------------ DrawHVACS ------------------------ */

void DrawHVACS(void){
  int i;

  for(i=0; i<nhvacinfo; i++){
    hvacdata *hvaci;

    hvaci = hvacinfo + i;
    if(hvaci->display==0)continue;
    DrawHVAC(hvaci);
  }
}
