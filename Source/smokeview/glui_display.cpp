#define CPP
#include "options.h"
#include <stdio.h>
#include <string.h>
#include GLUT_H
#include <math.h>

#include "smokeviewvars.h"

GLUI *glui_labels=NULL;

GLUI_EditText *EDIT_LB_label_string=NULL;

#ifdef pp_BETA
GLUI_Spinner *SPINNER_cullgeom_portsize=NULL;
#endif

GLUI_Listbox *LIST_LB_labels=NULL;

#ifdef pp_REFRESH
GLUI_Spinner *SPINNER_refresh_rate=NULL;
#endif

GLUI_Spinner *SPINNER_LB_tick_xbeg=NULL;
GLUI_Spinner *SPINNER_LB_tick_ybeg=NULL;
GLUI_Spinner *SPINNER_LB_tick_zbeg=NULL;
GLUI_Spinner *SPINNER_LB_tick_xdir=NULL;
GLUI_Spinner *SPINNER_LB_tick_ydir=NULL;
GLUI_Spinner *SPINNER_LB_tick_zdir=NULL;
GLUI_Spinner *SPINNER_ntick_decimals = NULL;


GLUI_Spinner *SPINNER_light_az0=NULL;
GLUI_Spinner *SPINNER_light_az1=NULL;
GLUI_Spinner *SPINNER_light_elev0=NULL;
GLUI_Spinner *SPINNER_light_elev1=NULL;

GLUI_Spinner *SPINNER_LB_time_start=NULL;
GLUI_Spinner *SPINNER_LB_time_stop=NULL;
GLUI_Spinner *SPINNER_LB_red=NULL;
GLUI_Spinner *SPINNER_LB_green=NULL;
GLUI_Spinner *SPINNER_LB_blue=NULL;
GLUI_Spinner *SPINNER_LB_x=NULL;
GLUI_Spinner *SPINNER_LB_y=NULL;
GLUI_Spinner *SPINNER_LB_z=NULL;
GLUI_Spinner *SPINNER_tick_xmin=NULL;
GLUI_Spinner *SPINNER_tick_ymin=NULL;
GLUI_Spinner *SPINNER_tick_zmin=NULL;
GLUI_Spinner *SPINNER_tick_xmax=NULL;
GLUI_Spinner *SPINNER_tick_ymax=NULL;
GLUI_Spinner *SPINNER_tick_zmax=NULL;
GLUI_Spinner *SPINNER_gridlinewidth = NULL;
GLUI_Spinner *SPINNER_ticklinewidth = NULL;
GLUI_Spinner *SPINNER_linewidth=NULL;
GLUI_Spinner *SPINNER_zone_hvac_diam = NULL;
GLUI_Spinner *SPINNER_tick_x0=NULL;
GLUI_Spinner *SPINNER_tick_y0=NULL;
GLUI_Spinner *SPINNER_tick_z0=NULL;
GLUI_Spinner *SPINNER_tick_dx0=NULL;
GLUI_Spinner *SPINNER_tick_dy0=NULL;
GLUI_Spinner *SPINNER_tick_dz0=NULL;
GLUI_Spinner *SPINNER_labels_transparency_face=NULL;
GLUI_Spinner *SPINNER_subtick=NULL;
GLUI_Spinner *SPINNER_scaled_font2d_height=NULL;
GLUI_Spinner *SPINNER_scaled_font3d_height=NULL;
GLUI_Spinner *SPINNER_scaled_font2d_height2width=NULL;
GLUI_Spinner *SPINNER_scaled_font3d_height2width=NULL;
GLUI_Spinner *SPINNER_scaled_font3d_thickness=NULL;
GLUI_Spinner *SPINNER_scaled_font2d_thickness=NULL;
GLUI_Spinner *SPINNER_northangle_position_x = NULL;
GLUI_Spinner *SPINNER_northangle_position_y = NULL;
GLUI_Spinner *SPINNER_northangle_position_z = NULL;
GLUI_Spinner *SPINNER_sliceoffset_factor=NULL;
GLUI_Spinner *SPINNER_ventoffset_factor=NULL;
GLUI_Spinner *SPINNER_amb_red=NULL;
GLUI_Spinner *SPINNER_amb_green=NULL;
GLUI_Spinner *SPINNER_amb_blue=NULL;
GLUI_Spinner *SPINNER_amb_grey=NULL;
GLUI_Spinner *SPINNER_diff_red=NULL;
GLUI_Spinner *SPINNER_diff_green=NULL;
GLUI_Spinner *SPINNER_diff_blue=NULL;
GLUI_Spinner *SPINNER_diff_grey=NULL;
GLUI_Spinner *SPINNER_spec_red = NULL;
GLUI_Spinner *SPINNER_spec_green = NULL;
GLUI_Spinner *SPINNER_spec_blue = NULL;
GLUI_Spinner *SPINNER_spec_grey = NULL;
GLUI_Spinner *SPINNER_shininess = NULL;
GLUI_Spinner *SPINNER_ngridloc_digits = NULL;

GLUI_Checkbox *CHECKBOX_visaxislabels = NULL;
GLUI_Checkbox *CHECKBOX_labels_showtick = NULL;
GLUI_Checkbox *CHECKBOX_labels_meshlabel = NULL;
GLUI_Checkbox *CHECKBOX_labels_version=NULL;
GLUI_Checkbox *CHECKBOX_visUSERticks=NULL;
GLUI_Checkbox *CHECKBOX_visUSERticks2=NULL;
#ifdef pp_BETA
GLUI_Checkbox *CHECKBOX_cullgeom=NULL;
#endif
GLUI_Checkbox *CHECKBOX_LB_visLabels=NULL;
GLUI_Checkbox *CHECKBOX_LB_label_use_foreground=NULL;
GLUI_Checkbox *CHECKBOX_LB_label_show_always=NULL;
GLUI_Checkbox *CHECKBOX_visColorbarVertical=NULL;
GLUI_Checkbox *CHECKBOX_visColorbarHorizontal = NULL;
GLUI_Checkbox *CHECKBOX_labels_timebar=NULL;
GLUI_Checkbox *CHECKBOX_labels_ticks=NULL;
GLUI_Checkbox *CHECKBOX_labels_title=NULL;
GLUI_Checkbox *CHECKBOX_labels_chid=NULL;
GLUI_Checkbox *CHECKBOX_labels_axis=NULL;
GLUI_Checkbox *CHECKBOX_labels_hms=NULL;
GLUI_Checkbox *CHECKBOX_labels_framerate=NULL;
GLUI_Checkbox *CHECKBOX_labels_timelabel=NULL;
GLUI_Checkbox *CHECKBOX_labels_framelabel=NULL;
GLUI_Checkbox *CHECKBOX_labels_frametimelabel = NULL;
GLUI_Checkbox *CHECKBOX_labels_hrrlabel=NULL;
GLUI_Checkbox *CHECKBOX_labels_firecutoff=NULL;
GLUI_Checkbox *CHECKBOX_labels_availmemory=NULL;
GLUI_Checkbox *CHECKBOX_labels_labels=NULL;
GLUI_Checkbox *CHECKBOX_labels_gridloc=NULL;
GLUI_Checkbox *CHECKBOX_labels_average=NULL;
GLUI_Checkbox *CHECKBOX_user_ticks_show_x=NULL;
GLUI_Checkbox *CHECKBOX_user_ticks_show_y=NULL;
GLUI_Checkbox *CHECKBOX_user_ticks_show_z=NULL;
GLUI_Checkbox *CHECKBOX_tick_auto=NULL;
GLUI_Checkbox *CHECKBOX_label_1=NULL;
GLUI_Checkbox *CHECKBOX_label_2=NULL;
GLUI_Checkbox *CHECKBOX_label_3=NULL;
GLUI_Checkbox *CHECKBOX_labels_flip=NULL;
GLUI_Checkbox *CHECKBOX_labels_transparent_override=NULL;
GLUI_Checkbox *CHECKBOX_shownorth = NULL;
GLUI_Checkbox *CHECKBOX_ticks_inside = NULL;
GLUI_Checkbox *CHECKBOX_ticks_outside = NULL;
GLUI_Checkbox *CHECKBOX_labels_fds_title = NULL;

GLUI_Rollout *ROLLOUT_LB_tick0 = NULL;
GLUI_Rollout *ROLLOUT_font=NULL;
GLUI_Rollout *ROLLOUT_user_labels=NULL;
GLUI_Rollout *ROLLOUT_user_tick=NULL;
GLUI_Rollout *ROLLOUT_general=NULL;
GLUI_Rollout *ROLLOUT_north = NULL;
GLUI_Rollout *ROLLOUT_light2 = NULL;

GLUI_Panel *PANEL_titles=NULL;
GLUI_Panel *PANEL_light=NULL;
GLUI_Panel *PANEL_position0=NULL;
GLUI_Panel *PANEL_position1 = NULL;
GLUI_Panel *PANEL_ambient=NULL;
GLUI_Panel *PANEL_diffuse=NULL;
GLUI_Panel *PANEL_specular = NULL;
GLUI_Panel *PANEL_positional = NULL;
GLUI_Panel *PANEL_positional2 = NULL;
GLUI_Panel *PANEL_timebar_overlap = NULL;
GLUI_Panel *PANEL_gen1=NULL, *PANEL_gen2=NULL, *PANEL_gen3=NULL;
GLUI_Panel *PANEL_LB_panel1=NULL, *PANEL_LB_panel2=NULL, *PANEL_LB_panel3=NULL;
GLUI_Panel *PANEL_LB_panel4=NULL, *PANEL_LB_panel5=NULL, *PANEL_LB_panel6=NULL;
GLUI_Panel *PANEL_LB_color=NULL, *PANEL_LB_time=NULL;
GLUI_Panel *PANEL_LB_position=NULL;
GLUI_Panel *PANEL_label2=NULL;
GLUI_Panel *PANEL_tick1;
GLUI_Panel *PANEL_tick1a;
GLUI_Panel *PANEL_tick1b;
GLUI_Panel *PANEL_tick2;
GLUI_Panel *PANEL_transparency = NULL;
GLUI_Panel *PANEL_font2d=NULL;
GLUI_Panel *PANEL_font3d=NULL;
GLUI_Panel *PANEL_LB_tick = NULL;
GLUI_Panel *PANEL_linewidth = NULL;
GLUI_Panel *PANEL_offset = NULL;

GLUI_RadioGroup *RADIO_timebar_overlap = NULL;
GLUI_RadioGroup *RADIO_fontsize = NULL;
GLUI_RadioButton *RADIOBUTTON_label_1a=NULL;
GLUI_RadioButton *RADIOBUTTON_label_1b=NULL;
GLUI_RadioButton *RADIOBUTTON_label_1c=NULL;

GLUI_Button *BUTTON_LB_label_previous=NULL;
GLUI_Button *BUTTON_LB_label_next=NULL;
GLUI_Button *BUTTON_LB_label_update=NULL;
GLUI_Button *BUTTON_LB_label_add=NULL;
GLUI_Button *BUTTON_LB_label_delete=NULL;
GLUI_Button *BUTTON_LB_label_set=NULL;
GLUI_Button *BUTTON_label_1=NULL;
GLUI_Button *BUTTON_label_2=NULL;
GLUI_Button *BUTTON_label_3=NULL;
GLUI_Button *BUTTON_label_4=NULL;

#define COLORBAR_EXTREME_RGB 15
#define COLORBAR_EXTREME 16
#define FLIP 19
#define APPLY_VENTOFFSET 20

#define LB_LIST 0
#define LB_ADD 1
#define LB_DELETE 2
#define LB_RGB 3
#define LB_XYZ 4
#define LB_STARTSTOP 5
#define LB_SHOWALWAYS 6
#define LB_FOREGROUND 7
#define LB_UPDATE 8
#define LB_PREVIOUS 9
#define LB_NEXT 10
#define LB_VISLABELS 11
#define LB_TICK_XYZ 12
#define LB_SHOW_TICK 13

#define LABELS_label           0
//#define LABELS_vcolorbar      34  movied to smokeviewdefs.h
//#define LABELS_hcolorbar      35  movied to smokeviewdefs.h
#define FRAME_label           21
#define HRR_label             22
#define FIRECUTOFF_label      23
#define LABELS_showall         1
#define LABELS_hideall         2
#define LABELS_close           3
#define LABELS_flip            4
//#define LABELS_shade           5   movied to smokeviewdefs.h
#define LABELS_transparent     6
#define LABELS_fontsize        7
#define LABELS_ticks           8
#define LABELS_drawface       24
#define LABELS_hide_overlaps  25
#define LABELS_version        26
#define LABELS_meshlabel      27
#define LABELS_usertick       28
#define LABELS_usertick2      29
//#define LABELS_shadedata      30   movied to smokeviewdefs.h
#define LABELS_shownorth      31
#define LABELS_tick_inside    32
#define LABELS_tick_outside   33
//#define LABELS_colorbar_shift 36  movied to smokeviewdefs.h
#ifdef pp_REFRESH
#define LABELS_REFRESH_RATE   37
#endif


#define SPLIT_COLORBAR 1

#define LABELS_HMS 18
#define SAVE_SETTINGS_DISPLAY 99

#define COLORBAND 115
#define CB_USE_LIGHTING 120
#define COLOR_AMB_GREY 116
#define COLOR_DIFF_GREY 117
#define COLOR_AMB_RGB 118
#define COLOR_DIFF_RGB 119
#define COLOR_SPEC_RGB 120
#define COLOR_SPEC_GREY 121
#define LIGHT_POSITION 122
#define COLORLABEL_DIGITS 123

#define COLORBAR_LIST2 112
#define DATA_transparent 26
#define TRANSPARENTLEVEL 110

#define UPDATEPLOT 10


#define GENERAL_ROLLOUT 0
#define COLORING_ROLLOUT 1
#define FONTS_ROLLOUT 2
#define TICKS_ROLLOUT 3
#define LABELS_ROLLOUT 4
#define LIGHT_ROLLOUT 5

#define UPDATEMENU 1

procdata displayprocinfo[6];
int ndisplayprocinfo = 0;

/* ------------------ UpdateVisAxisLabels ------------------------ */

extern "C" void UpdateVisAxisLabels(void){
  if(CHECKBOX_visaxislabels!=NULL)CHECKBOX_visaxislabels->set_int_val(visaxislabels);
}

/* ------------------ UpdateFrameTimelabel ------------------------ */

extern "C" void UpdateFrameTimelabel(void) {
  CHECKBOX_labels_frametimelabel->set_int_val(visFrameTimelabel);
}

/* ------------------ UpdateBackgroundFlip ------------------------ */

extern "C" void UpdateBackgroundFlip(int flip) {
  CHECKBOX_labels_flip->set_int_val(flip);
}

/* ------------------ UpdateTimebarOverlap ------------------------ */

extern "C" void UpdateTimebarOverlap(void) {
  RADIO_timebar_overlap->set_int_val(timebar_overlap);
}

/* ------------------ DisplayRolloutCB ------------------------ */

void DisplayRolloutCB(int var){
  ToggleRollout(displayprocinfo, ndisplayprocinfo, var);
}

/* ------------------ UpdateGluiLabelText ------------------------ */

extern "C" void UpdateGluiLabelText(void){
  if(LabelGetNUserLabels()>0){
    labeldata *gl;

    gl=&LABEL_local;

    LIST_LB_labels->set_int_val(gl->glui_id);
    EDIT_LB_label_string->set_text(gl->name);
    SPINNER_LB_x->set_float_val(gl->xyz[0]);
    SPINNER_LB_y->set_float_val(gl->xyz[1]);
    SPINNER_LB_z->set_float_val(gl->xyz[2]);
    SPINNER_LB_tick_xbeg->set_float_val(gl->tick_begin[0]);
    SPINNER_LB_tick_ybeg->set_float_val(gl->tick_begin[1]);
    SPINNER_LB_tick_zbeg->set_float_val(gl->tick_begin[2]);
    SPINNER_LB_tick_xdir->set_float_val(gl->tick_direction[0]);
    SPINNER_LB_tick_ydir->set_float_val(gl->tick_direction[1]);
    SPINNER_LB_tick_zdir->set_float_val(gl->tick_direction[2]);
    CHECKBOX_labels_showtick->set_int_val(gl->show_tick);


    SPINNER_LB_time_start->set_float_val(gl->tstart_stop[0]);
    SPINNER_LB_time_stop->set_float_val(gl->tstart_stop[1]);
    CHECKBOX_LB_label_show_always->set_int_val(gl->show_always);

    SPINNER_LB_red->set_int_val(gl->rgb[0]);
    SPINNER_LB_green->set_int_val(gl->rgb[1]);
    SPINNER_LB_blue->set_int_val(gl->rgb[2]);
    CHECKBOX_LB_label_use_foreground->set_int_val(gl->useforegroundcolor);

    CHECKBOX_LB_visLabels->enable();
    LIST_LB_labels->enable();
    EDIT_LB_label_string->enable();
    ROLLOUT_LB_tick0->enable();
    PANEL_LB_position->enable();
    PANEL_LB_time->enable();
    PANEL_LB_color->enable();
  }
  else{
    CHECKBOX_LB_visLabels->disable();
    LIST_LB_labels->disable();
    EDIT_LB_label_string->disable();
    ROLLOUT_LB_tick0->disable();
    PANEL_LB_position->disable();
    PANEL_LB_time->disable();
    PANEL_LB_color->disable();
  }
}

  /* ------------------ GluiUpdateFontIndex ------------------------ */

extern "C" void GluiUpdateFontIndex(void){
  if(RADIO_fontsize!=NULL){
    if(fontindex==SCALED_FONT){
      SPINNER_scaled_font2d_height->enable();
      SPINNER_scaled_font3d_height->enable();
      SPINNER_scaled_font2d_height2width->enable();
      SPINNER_scaled_font3d_height2width->enable();
      SPINNER_scaled_font2d_thickness->enable();
      SPINNER_scaled_font3d_thickness->enable();
    }
    else{
      SPINNER_scaled_font2d_height->disable();
      SPINNER_scaled_font3d_height->disable();
      SPINNER_scaled_font2d_height2width->disable();
      SPINNER_scaled_font3d_height2width->disable();
      SPINNER_scaled_font2d_thickness->disable();
      SPINNER_scaled_font3d_thickness->disable();
    }
  }
}

/* ------------------ TextLabelsCB ------------------------ */

void TextLabelsCB(int var){
  labeldata *thislabel, *gl, *new_label;
  int count;
  char name[300];

  gl = &LABEL_local;
  switch(var){
  case LB_VISLABELS:
    updatemenu = 1;
    break;
  case LB_UPDATE:
    for(thislabel = label_first_ptr->next;thislabel->next != NULL;thislabel = thislabel->next){
      if(thislabel->glui_id < 0)continue;
      LIST_LB_labels->delete_item(thislabel->glui_id);
    }
    strcpy(LABEL_global_ptr->name, gl->name);
    //LabelResort(LABEL_global_ptr);

    count = 0;
    for(thislabel = label_first_ptr->next;thislabel->next != NULL;thislabel = thislabel->next){
      if(thislabel->labeltype == TYPE_SMV)continue;
      thislabel->glui_id = count;
      LIST_LB_labels->add_item(count++, thislabel->name);
    }
    break;
  case LB_STARTSTOP:
    memcpy(LABEL_global_ptr->tstart_stop, gl->tstart_stop, 2 * sizeof(float));
    break;
  case LB_SHOWALWAYS:
    memcpy(&LABEL_global_ptr->show_always, &gl->show_always, sizeof(int));
    break;
  case LB_FOREGROUND:
    memcpy(&LABEL_global_ptr->useforegroundcolor, &gl->useforegroundcolor, sizeof(int));
    break;
  case LB_PREVIOUS:
    new_label = LabelGet(LIST_LB_labels->curr_text);
    new_label = LabelPrevious(new_label);
    if(new_label == NULL)break;
    LABEL_global_ptr = new_label;
    if(new_label != NULL){
      LabelCopy(gl, new_label);
      UpdateGluiLabelText();
    }
    break;
  case LB_NEXT:
    new_label = LabelGet(LIST_LB_labels->curr_text);
    new_label = LabelNext(new_label);
    if(new_label == NULL)break;
    LABEL_global_ptr = new_label;
    if(new_label != NULL){
      LabelCopy(gl, new_label);
      UpdateGluiLabelText();
    }
    break;
  case LB_LIST:
    new_label = LabelGet(LIST_LB_labels->curr_text);
    LABEL_global_ptr = new_label;
    if(new_label != NULL){
      LabelCopy(gl, new_label);
    }
    UpdateGluiLabelText();
    break;
  case LB_ADD:
    updatemenu = 1;
    if(LabelGetNUserLabels() > 0){
      strcpy(name, "copy of ");
      strcat(name, gl->name);
      strcpy(gl->name, name);
    }
    else{
      gl = &LABEL_default;
    }
    gl->labeltype = TYPE_INI;
    for(thislabel = label_first_ptr->next;thislabel->next != NULL;thislabel = thislabel->next){
      if(thislabel->glui_id < 0)continue;
      LIST_LB_labels->delete_item(thislabel->glui_id);
    }
    LabelInsert(gl);
    count = 0;
    for(thislabel = label_first_ptr->next;thislabel->next != NULL;thislabel = thislabel->next){
      if(thislabel->labeltype == TYPE_SMV)continue;
      thislabel->glui_id = count;
      LIST_LB_labels->add_item(count++, thislabel->name);
    }
    TextLabelsCB(LB_LIST);
    break;
  case LB_DELETE:
    strcpy(name, LIST_LB_labels->curr_text);
    for(thislabel = label_first_ptr->next;thislabel->next != NULL;thislabel = thislabel->next){
      if(thislabel->glui_id < 0)continue;
      LIST_LB_labels->delete_item(thislabel->glui_id);
    }
    thislabel = LabelGet(name);
    if(thislabel != NULL){
      LabelDelete(thislabel);
    }
    count = 0;
    for(thislabel = label_first_ptr->next;thislabel->next != NULL;thislabel = thislabel->next){
      if(thislabel->labeltype == TYPE_SMV)continue;
      thislabel->glui_id = count;
      LIST_LB_labels->add_item(count++, thislabel->name);
    }
    TextLabelsCB(LB_LIST);
    break;
  case LB_RGB:
    gl->frgb[0] = gl->rgb[0] / 255.0;
    gl->frgb[1] = gl->rgb[1] / 255.0;
    gl->frgb[2] = gl->rgb[2] / 255.0;
    memcpy(LABEL_global_ptr->frgb, gl->frgb, 3 * sizeof(float));
    memcpy(LABEL_global_ptr->rgb, gl->rgb, 3 * sizeof(int));
    break;
  case LB_XYZ:
    memcpy(LABEL_global_ptr->xyz, gl->xyz, 3 * sizeof(float));
    break;
  case LB_TICK_XYZ:
    memcpy(LABEL_global_ptr->tick_begin, gl->tick_begin, 3 * sizeof(float));
    memcpy(LABEL_global_ptr->tick_direction, gl->tick_direction, 3 * sizeof(float));
    break;
  case LB_SHOW_TICK:
    memcpy(&LABEL_global_ptr->show_tick, &gl->show_tick, sizeof(int));
    break;
  default:
    ASSERT(FFALSE);
    break;
  }
}

/* ------------------ ColorCB ------------------------ */

extern "C" void ColorCB(int var){
  int i;

  switch (var){
  case LIGHT_POSITION:
    light_position0[0] = (xyzmaxdiff/2.0)*cos(DEG2RAD*glui_light_az0)*cos(DEG2RAD*glui_light_elev0);
    light_position0[1] = (xyzmaxdiff/2.0)*sin(DEG2RAD*glui_light_az0)*cos(DEG2RAD*glui_light_elev0);
    light_position0[2] = (xyzmaxdiff/2.0)*sin(DEG2RAD*glui_light_elev0);

    light_position1[0] = (xyzmaxdiff/2.0)*cos(DEG2RAD*glui_light_az1)*cos(DEG2RAD*glui_light_elev1);
    light_position1[1] = (xyzmaxdiff/2.0)*sin(DEG2RAD*glui_light_az1)*cos(DEG2RAD*glui_light_elev1);
    light_position1[2] = (xyzmaxdiff/2.0)*sin(DEG2RAD*glui_light_elev1);
    break;
  case COLOR_SPEC_RGB:
    for(i = 0; i<3; i++){
      specularlight[i] = (float)glui_specularlight[i]/255.0;
    }
    glui_speculargrey = CLAMP(255*TOBW(specularlight), 0, 255);
    SPINNER_spec_grey->set_int_val(glui_speculargrey);
    break;
  case COLOR_AMB_RGB:
    for(i = 0; i<3; i++){
      ambientlight[i] = (float)glui_ambientlight[i]/255.0;
    }
    glui_ambientgrey = CLAMP(255*TOBW(ambientlight),0,255);
    SPINNER_amb_grey->set_int_val(glui_ambientgrey);
    break;
  case COLOR_DIFF_RGB:
    for(i = 0; i<3; i++){
      diffuselight[i] = (float)glui_diffuselight[i]/255.0;
    }
    glui_diffusegrey = CLAMP(255*TOBW(diffuselight),0,255);
    SPINNER_diff_grey->set_int_val(glui_diffusegrey);
    break;
  case COLOR_SPEC_GREY:
    for(i = 0; i<3; i++){
      glui_specularlight[i] = glui_speculargrey;
      specularlight[i] = CLAMP((float)glui_speculargrey/255.0, 0.0, 1.0);
    }
    for(i = 0; i<3; i++){
      ambientlight[i] = CLAMP((float)glui_ambientlight[i]/255.0, 0.0, 1.0);
    }
    SPINNER_spec_red->set_int_val(glui_speculargrey);
    SPINNER_spec_green->set_int_val(glui_speculargrey);
    SPINNER_spec_blue->set_int_val(glui_speculargrey);
    break;
  case COLOR_AMB_GREY:
    for(i = 0; i<3; i++){
      glui_ambientlight[i] = glui_ambientgrey;
      ambientlight[i] = CLAMP((float)glui_ambientgrey/255.0,0.0,1.0);
    }
    for(i = 0; i<3; i++){
      ambientlight[i] = CLAMP((float)glui_ambientlight[i]/255.0,0.0,1.0);
    }
    SPINNER_amb_red->set_int_val(glui_ambientgrey);
    SPINNER_amb_green->set_int_val(glui_ambientgrey);
    SPINNER_amb_blue->set_int_val(glui_ambientgrey);
  break;
  case COLOR_DIFF_GREY:
    if(glui_shininess<1.0){
      glui_shininess = 1.0;
      SPINNER_shininess->set_float_val(glui_shininess);
    }
    iso_shininess = glui_shininess;
    for(i = 0; i<3; i++){
      glui_diffuselight[i] = glui_diffusegrey;
      diffuselight[i] = (float)glui_diffusegrey/255.0;
    }
    SPINNER_diff_red->set_int_val(glui_diffusegrey);
    SPINNER_diff_green->set_int_val(glui_diffusegrey);
    SPINNER_diff_blue->set_int_val(glui_diffusegrey);
  break;
  }
}

/* ------------------ UpdateGLuiGridLocation ------------------------ */

extern "C" void UpdateGLuiGridLocation(void){
  SPINNER_ngridloc_digits->set_int_val(ngridloc_digits);
}

/* ------------------ UpdateMenuCB ------------------------ */

void UpdateMenuCB(int var){
  updatemenu = 1;
}

/* ------------------ GluiLabelsSetup ------------------------ */

extern "C" void GluiLabelsSetup(int main_window){
  labeldata *gl;

  if(glui_labels!=NULL){
    glui_labels->close();
    glui_labels=NULL;
  }
  glui_labels = GLUI_Master.create_glui("Display",0,0,0);
  glui_labels->hide();

  // -------------- General Settings -------------------

  ROLLOUT_general = glui_labels->add_rollout(_("General"),true,GENERAL_ROLLOUT,DisplayRolloutCB);
  INSERT_ROLLOUT(ROLLOUT_general, glui_labels);
  ADDPROCINFO(displayprocinfo, ndisplayprocinfo, ROLLOUT_general, GENERAL_ROLLOUT, glui_labels);

  PANEL_gen1=glui_labels->add_panel_to_panel(ROLLOUT_general,"",GLUI_PANEL_NONE);

  if(nsliceinfo>0)CHECKBOX_labels_average = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Average"), &vis_slice_average, LABELS_label, LabelsCB);
  CHECKBOX_labels_axis = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Axis"), &visaxislabels, LABELS_label, LabelsCB);
  CHECKBOX_visColorbarVertical   = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Colorbar(vertical)"),   &visColorbarVertical,   LABELS_vcolorbar, LabelsCB);
  CHECKBOX_visColorbarHorizontal = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Colorbar(horizontal)"), &visColorbarHorizontal, LABELS_hcolorbar, LabelsCB);
  CHECKBOX_labels_timebar = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Timebar"), &visTimebar, LABELS_label, LabelsCB);
  CHECKBOX_labels_framelabel = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Frame"), &visFramelabel, LABELS_label, LabelsCB);
  CHECKBOX_labels_timelabel = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Time"), &visTimelabel, LABELS_label, LabelsCB);
  CHECKBOX_labels_frametimelabel = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Frame/time label"), &visFrameTimelabel, LABELS_label, LabelsCB);
  CHECKBOX_labels_framerate = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Frame rate"), &visFramerate, LABELS_label, LabelsCB);
  CHECKBOX_labels_gridloc = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Grid location"), &visgridloc, LABELS_label, LabelsCB);
  CHECKBOX_labels_hrrlabel = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("HRR"), &visHRRlabel, HRR_label, LabelsCB);
  CHECKBOX_labels_firecutoff = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Fire cutoff"), &show_firecutoff, FIRECUTOFF_label, LabelsCB);
#ifdef pp_memstatus
  CHECKBOX_labels_availmemory = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Memory load"), &visAvailmemory, LABELS_label, LabelsCB);
#endif

  glui_labels->add_column_to_panel(PANEL_gen1, false);

  CHECKBOX_labels_meshlabel = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Mesh"), &visMeshlabel, LABELS_meshlabel, LabelsCB);
  CHECKBOX_labels_labels = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Text labels"), &visLabels, LABELS_label, LabelsCB);
  CHECKBOX_labels_ticks = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Ticks (FDS)"), &visFDSticks, LABELS_label, LabelsCB);
  CHECKBOX_visUSERticks2 = glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Ticks (User)"), &visUSERticks, LABELS_usertick2, LabelsCB);
  glui_labels->add_checkbox_to_panel(PANEL_gen1, _("Toggle dialogs"), &toggle_dialogs);
#ifdef pp_REFRESH
  SPINNER_refresh_rate = glui_labels->add_spinner_to_panel(PANEL_gen1, _("refresh rate (fps)"), GLUI_SPINNER_INT, &glui_refresh_rate, LABELS_REFRESH_RATE, LabelsCB);
  SPINNER_refresh_rate->set_int_limits(0,10);
#endif

  PANEL_titles=glui_labels->add_panel_to_panel(PANEL_gen1,"Titles");
  CHECKBOX_labels_title = glui_labels->add_checkbox_to_panel(PANEL_titles,     _("Smokeview version, build date"), &vis_title_smv_version, LABELS_label,   LabelsCB);
  CHECKBOX_labels_version = glui_labels->add_checkbox_to_panel(PANEL_titles,   _("FDS, Smokeview version"),        &vis_title_gversion,    LABELS_version, LabelsCB);
  CHECKBOX_labels_fds_title = glui_labels->add_checkbox_to_panel(PANEL_titles, _("Input file title"),              &vis_title_fds,         LABELS_label,   LabelsCB);
  CHECKBOX_labels_chid = glui_labels->add_checkbox_to_panel(PANEL_titles,      _("CHID"),                          &vis_title_CHID,        LABELS_label,   LabelsCB);

  if(ntickinfo>0){
    CHECKBOX_labels_ticks->enable();
  }
  else{
    CHECKBOX_labels_ticks->disable();
    visFDSticks=0;
    CHECKBOX_labels_ticks->set_int_val(visFDSticks);
  }

  PANEL_gen2=glui_labels->add_panel_to_panel(ROLLOUT_general,"",GLUI_PANEL_NONE);

  BUTTON_label_1=glui_labels->add_button_to_panel(PANEL_gen2,_("Show all"),LABELS_showall,LabelsCB);
  glui_labels->add_column_to_panel(PANEL_gen2,false);
  BUTTON_label_2=glui_labels->add_button_to_panel(PANEL_gen2,_("Hide all"),LABELS_hideall,LabelsCB);

  glui_labels->add_separator_to_panel(ROLLOUT_general);

  PANEL_gen3=glui_labels->add_panel_to_panel(ROLLOUT_general,"",GLUI_PANEL_NONE);

  PANEL_linewidth=glui_labels->add_panel_to_panel(PANEL_gen3,"line width");
  SPINNER_linewidth=glui_labels->add_spinner_to_panel(PANEL_linewidth,_("blockage"),GLUI_SPINNER_FLOAT,&linewidth);
  SPINNER_linewidth->set_float_limits(1.0,10.0,GLUI_LIMIT_CLAMP);
  SPINNER_gridlinewidth=glui_labels->add_spinner_to_panel(PANEL_linewidth,_("grid"),GLUI_SPINNER_FLOAT,&gridlinewidth);
  SPINNER_gridlinewidth->set_float_limits(1.0,10.0,GLUI_LIMIT_CLAMP);
  SPINNER_ticklinewidth = glui_labels->add_spinner_to_panel(PANEL_linewidth, _("tick"), GLUI_SPINNER_FLOAT, &ticklinewidth);
  SPINNER_ticklinewidth->set_float_limits(1.0, 10.0, GLUI_LIMIT_CLAMP);
  PANEL_offset=glui_labels->add_panel_to_panel(PANEL_gen3,"offset");
  SPINNER_ventoffset_factor=glui_labels->add_spinner_to_panel(PANEL_offset,_("vent"),GLUI_SPINNER_FLOAT,&ventoffset_factor,APPLY_VENTOFFSET,LabelsCB);
  SPINNER_ventoffset_factor->set_float_limits(-1.0,1.0,GLUI_LIMIT_CLAMP);
  SPINNER_sliceoffset_factor=glui_labels->add_spinner_to_panel(PANEL_offset,_("slice"),GLUI_SPINNER_FLOAT,&sliceoffset_factor);
  SPINNER_sliceoffset_factor->set_float_limits(-1.0,1.0,GLUI_LIMIT_CLAMP);

  SPINNER_ngridloc_digits = glui_labels->add_spinner_to_panel(PANEL_gen3, _("grid location digits:"),
    GLUI_SPINNER_INT, &ngridloc_digits, UPDATEMENU, UpdateMenuCB);
  SPINNER_ngridloc_digits->set_int_limits(GRIDLOC_NDECIMALS_MIN, GRIDLOC_NDECIMALS_MAX, GLUI_LIMIT_CLAMP);

  CHECKBOX_visaxislabels = glui_labels->add_checkbox_to_panel(PANEL_gen3, _("Show axis labels"), &visaxislabels, UPDATEMENU, UpdateMenuCB);

  if(nzoneinfo > 0){
    SPINNER_zone_hvac_diam = glui_labels->add_spinner_to_panel(PANEL_gen3, "HVAC (cfast)", GLUI_SPINNER_FLOAT, &zone_hvac_diam);
    SPINNER_zone_hvac_diam->set_float_limits(0.0, 1.0, GLUI_LIMIT_CLAMP);
  }

  if(have_northangle==1){
    ROLLOUT_north = glui_labels->add_rollout_to_panel(PANEL_gen3,_("North direction"),false);
    INSERT_ROLLOUT(ROLLOUT_north, glui_labels);
    CHECKBOX_shownorth=glui_labels->add_checkbox_to_panel(ROLLOUT_north,_("show"),&vis_northangle,LABELS_shownorth,LabelsCB);
    SPINNER_northangle_position_x = glui_labels->add_spinner_to_panel(ROLLOUT_north, "x:", GLUI_SPINNER_FLOAT, northangle_position);
    SPINNER_northangle_position_y = glui_labels->add_spinner_to_panel(ROLLOUT_north, "y:", GLUI_SPINNER_FLOAT, northangle_position+1);
    SPINNER_northangle_position_z = glui_labels->add_spinner_to_panel(ROLLOUT_north, "z:", GLUI_SPINNER_FLOAT, northangle_position+2);
  }

  glui_labels->add_column_to_panel(PANEL_gen3,false);

  CHECKBOX_labels_flip = glui_labels->add_checkbox_to_panel(PANEL_gen3, _("Flip background"), &background_flip, LABELS_flip, LabelsCB);
  CHECKBOX_labels_hms = glui_labels->add_checkbox_to_panel(PANEL_gen3, _("hms time"), &vishmsTimelabel, LABELS_HMS, LabelsCB);
  PANEL_timebar_overlap = glui_labels->add_panel_to_panel(PANEL_gen3,_("Overlap timebar region"));
  RADIO_timebar_overlap=glui_labels->add_radiogroup_to_panel(PANEL_timebar_overlap,&timebar_overlap);
  glui_labels->add_radiobutton_to_group(RADIO_timebar_overlap,_("Always"));
  glui_labels->add_radiobutton_to_group(RADIO_timebar_overlap,_("Never"));
  glui_labels->add_radiobutton_to_group(RADIO_timebar_overlap,_("Only if timebar hidden"));

  CHECKBOX_label_1=glui_labels->add_checkbox_to_panel(PANEL_gen3,_("Fast blockage drawing"),&use_new_drawface,LABELS_drawface,LabelsCB);
  CHECKBOX_label_2=glui_labels->add_checkbox_to_panel(PANEL_gen3,_("Sort transparent faces"),&sort_transparent_faces,LABELS_drawface,LabelsCB);
  CHECKBOX_label_3=glui_labels->add_checkbox_to_panel(PANEL_gen3,_("Hide overlaps"),&hide_overlaps,LABELS_hide_overlaps,LabelsCB);

  if(nface_transparent>0){
    glui_labels->add_column_to_panel(PANEL_gen1,true);
    PANEL_transparency = glui_labels->add_panel_to_panel(PANEL_gen3,_("Geometry transparency"));
    CHECKBOX_labels_transparent_override=glui_labels->add_checkbox_to_panel(PANEL_transparency,_("Use level:"),&use_transparency_geom,LABELS_transparent,LabelsCB);
    SPINNER_labels_transparency_face=glui_labels->add_spinner_to_panel(PANEL_transparency,"",GLUI_SPINNER_FLOAT,&transparency_geom,LABELS_transparent,LabelsCB);
    SPINNER_labels_transparency_face->set_float_limits(0.0,1.0,GLUI_LIMIT_CLAMP);
    LabelsCB(LABELS_transparent);
  }


  ROLLOUT_light2 = glui_labels->add_rollout("Light",false,LIGHT_ROLLOUT,DisplayRolloutCB);
  INSERT_ROLLOUT(ROLLOUT_light2, glui_labels);
  ADDPROCINFO(displayprocinfo, ndisplayprocinfo, ROLLOUT_light2, LIGHT_ROLLOUT, glui_labels);

  {
    int i;

    for(i = 0; i<3;i++){
      glui_ambientlight[i] = CLAMP(255*ambientlight[i],0,255);
      glui_diffuselight[i] = CLAMP(255*diffuselight[i],0,255);
    }
  }
  glui_ambientgrey = 255*ambientgrey;
  glui_diffusegrey = 255*diffusegrey;
  glui_speculargrey = 255*speculargrey;

  PANEL_light = glui_labels->add_panel_to_panel(ROLLOUT_light2, "",false);
  PANEL_ambient = glui_labels->add_panel_to_panel(PANEL_light, "background/ambient");
  SPINNER_amb_red = glui_labels->add_spinner_to_panel(PANEL_ambient, _("red:"),     GLUI_SPINNER_INT, glui_ambientlight,   COLOR_AMB_RGB,ColorCB);
  SPINNER_amb_green = glui_labels->add_spinner_to_panel(PANEL_ambient, _("green:"), GLUI_SPINNER_INT, glui_ambientlight+1, COLOR_AMB_RGB,ColorCB);
  SPINNER_amb_blue = glui_labels->add_spinner_to_panel(PANEL_ambient, _("blue:"),   GLUI_SPINNER_INT, glui_ambientlight+2, COLOR_AMB_RGB,ColorCB);
  SPINNER_amb_grey = glui_labels->add_spinner_to_panel(PANEL_ambient, _("grey:"),   GLUI_SPINNER_INT, &glui_ambientgrey,   COLOR_AMB_GREY,ColorCB);
  SPINNER_amb_red->set_int_limits(0,255);
  SPINNER_amb_green->set_int_limits(0, 255);
  SPINNER_amb_blue->set_int_limits(0, 255);
  SPINNER_amb_grey->set_int_limits(0, 255);
  ColorCB(COLOR_AMB_RGB);

  glui_labels->add_column_to_panel(PANEL_light,false);

  PANEL_diffuse = glui_labels->add_panel_to_panel(PANEL_light, "light/diffuse");
  SPINNER_diff_red = glui_labels->add_spinner_to_panel(PANEL_diffuse, _("red:"),     GLUI_SPINNER_INT, glui_diffuselight,   COLOR_DIFF_RGB,ColorCB);
  SPINNER_diff_green = glui_labels->add_spinner_to_panel(PANEL_diffuse, _("green:"), GLUI_SPINNER_INT, glui_diffuselight+1, COLOR_DIFF_RGB,ColorCB);
  SPINNER_diff_blue = glui_labels->add_spinner_to_panel(PANEL_diffuse, _("blue:"),   GLUI_SPINNER_INT, glui_diffuselight+2, COLOR_DIFF_RGB,ColorCB);
  SPINNER_diff_grey = glui_labels->add_spinner_to_panel(PANEL_diffuse, _("grey:"),   GLUI_SPINNER_INT, &glui_diffusegrey,   COLOR_DIFF_GREY,ColorCB);
  SPINNER_diff_red->set_int_limits(0,255);
  SPINNER_diff_green->set_int_limits(0, 255);
  SPINNER_diff_blue->set_int_limits(0, 255);
  SPINNER_diff_grey->set_int_limits(0, 255);
  ColorCB(COLOR_DIFF_RGB);
  SPINNER_shininess = glui_labels->add_spinner_to_panel(PANEL_diffuse, "shininess", GLUI_SPINNER_FLOAT, &glui_shininess,
                                                        COLOR_DIFF_GREY, ColorCB);

#ifdef pp_SPECULAR
  PANEL_specular = glui_labels->add_panel_to_panel(ROLLOUT_light2, "specular");
  SPINNER_spec_red = glui_labels->add_spinner_to_panel(PANEL_specular, _("red:"),     GLUI_SPINNER_INT, glui_specularlight,   COLOR_SPEC_RGB,  ColorCB);
  SPINNER_spec_green = glui_labels->add_spinner_to_panel(PANEL_specular, _("green:"), GLUI_SPINNER_INT, glui_specularlight+1, COLOR_SPEC_RGB,  ColorCB);
  SPINNER_spec_blue = glui_labels->add_spinner_to_panel(PANEL_specular, _("blue:"),   GLUI_SPINNER_INT, glui_specularlight+2, COLOR_SPEC_RGB,  ColorCB);
  SPINNER_spec_grey = glui_labels->add_spinner_to_panel(PANEL_specular, _("grey:"),   GLUI_SPINNER_INT, &glui_speculargrey,   COLOR_SPEC_GREY, ColorCB);
  SPINNER_spec_red->set_int_limits(0, 255);
  SPINNER_spec_green->set_int_limits(0, 255);
  SPINNER_spec_blue->set_int_limits(0, 255);
  SPINNER_spec_grey->set_int_limits(0, 255);
#endif

  PANEL_positional = glui_labels->add_panel_to_panel(ROLLOUT_light2, "direction");
  glui_labels->add_checkbox_to_panel(PANEL_positional, "show directions", &drawlights);


  PANEL_positional2 = glui_labels->add_panel_to_panel(PANEL_positional, "",false);
  PANEL_position0 = glui_labels->add_panel_to_panel(PANEL_positional2, "light 1");
  glui_labels->add_checkbox_to_panel(PANEL_position0, _("show"), &use_light0);
  SPINNER_light_az0 = glui_labels->add_spinner_to_panel(PANEL_position0,   "azimuth:",   GLUI_SPINNER_FLOAT, &glui_light_az0,   LIGHT_POSITION,ColorCB);
  SPINNER_light_elev0 = glui_labels->add_spinner_to_panel(PANEL_position0, "elevation:", GLUI_SPINNER_FLOAT, &glui_light_elev0, LIGHT_POSITION,ColorCB);
  SPINNER_light_az0->set_float_limits(-360.0,360.0);
  SPINNER_light_elev0->set_float_limits(-90.0,90.0);

  glui_labels->add_column_to_panel(PANEL_positional2,false);

  PANEL_position1 = glui_labels->add_panel_to_panel(PANEL_positional2, "light 2");
  glui_labels->add_checkbox_to_panel(PANEL_position1, "show", &use_light1);
  SPINNER_light_az1 = glui_labels->add_spinner_to_panel(PANEL_position1,   "azimuth:",   GLUI_SPINNER_FLOAT, &glui_light_az1,   LIGHT_POSITION,ColorCB);
  SPINNER_light_elev1 = glui_labels->add_spinner_to_panel(PANEL_position1, "elevation:", GLUI_SPINNER_FLOAT, &glui_light_elev1, LIGHT_POSITION,ColorCB);
  SPINNER_light_az1->set_float_limits(-360.0,360.0);
  SPINNER_light_elev1->set_float_limits(-90.0,90.0);
  ColorCB(LIGHT_POSITION);

  // -------------- Fonts -------------------

  ROLLOUT_font = glui_labels->add_rollout("Fonts",false,FONTS_ROLLOUT,DisplayRolloutCB);
  INSERT_ROLLOUT(ROLLOUT_font, glui_labels);
  ADDPROCINFO(displayprocinfo, ndisplayprocinfo, ROLLOUT_font, FONTS_ROLLOUT, glui_labels);

  RADIO_fontsize = glui_labels->add_radiogroup_to_panel(ROLLOUT_font,&fontindex,LABELS_fontsize,LabelsCB);
  RADIOBUTTON_label_1a=glui_labels->add_radiobutton_to_group(RADIO_fontsize,_("small"));
  RADIOBUTTON_label_1b=glui_labels->add_radiobutton_to_group(RADIO_fontsize,_("large"));
  RADIOBUTTON_label_1c=glui_labels->add_radiobutton_to_group(RADIO_fontsize,_("scaled"));

  PANEL_font2d = glui_labels->add_panel_to_panel(ROLLOUT_font,_("labels"),true);
  SPINNER_scaled_font2d_height=glui_labels->add_spinner_to_panel(PANEL_font2d,_("height:"),GLUI_SPINNER_INT,&scaled_font2d_height);
  SPINNER_scaled_font2d_height2width=glui_labels->add_spinner_to_panel(PANEL_font2d,_("height/width"),GLUI_SPINNER_FLOAT,&scaled_font2d_height2width);
  SPINNER_scaled_font2d_height2width->set_float_limits(0.5,1.5);
  SPINNER_scaled_font2d_thickness=glui_labels->add_spinner_to_panel(PANEL_font2d,_("thickness:"),GLUI_SPINNER_INT,&scaled_font2d_thickness);
  SPINNER_scaled_font2d_thickness->set_int_limits(1,10);

  PANEL_font3d = glui_labels->add_panel_to_panel(ROLLOUT_font,_("scene"),true);
  SPINNER_scaled_font3d_height=glui_labels->add_spinner_to_panel(PANEL_font3d,_("height:"),GLUI_SPINNER_INT,&scaled_font3d_height);
  SPINNER_scaled_font3d_height2width=glui_labels->add_spinner_to_panel(PANEL_font3d,_("height/width:"),GLUI_SPINNER_FLOAT,&scaled_font3d_height2width);
  SPINNER_scaled_font3d_height2width->set_float_limits(0.5,1.5);
  SPINNER_scaled_font3d_thickness=glui_labels->add_spinner_to_panel(PANEL_font3d,_("thickness:"),GLUI_SPINNER_INT,&scaled_font3d_thickness);
  SPINNER_scaled_font3d_thickness->set_int_limits(1,10);
  GluiUpdateFontIndex();

  // -------------- User tick settings -------------------

  ROLLOUT_user_tick = glui_labels->add_rollout("User ticks",false,TICKS_ROLLOUT,DisplayRolloutCB);
  INSERT_ROLLOUT(ROLLOUT_user_tick, glui_labels);
  ADDPROCINFO(displayprocinfo, ndisplayprocinfo, ROLLOUT_user_tick, TICKS_ROLLOUT, glui_labels);

  PANEL_tick1 = glui_labels->add_panel_to_panel(ROLLOUT_user_tick,_("Display"),true);
  PANEL_tick1a = glui_labels->add_panel_to_panel(PANEL_tick1,"",false);

  CHECKBOX_visUSERticks=glui_labels->add_checkbox_to_panel(PANEL_tick1a,_("Show user ticks"),&visUSERticks,LABELS_usertick,LabelsCB);
  glui_labels->add_column_to_panel(PANEL_tick1a,false);

  if(user_tick_direction>0.0){
    glui_tick_inside=0;
    glui_tick_outside=1;
  }
  else{
    glui_tick_inside=1;
    glui_tick_outside=0;
  }
  CHECKBOX_ticks_inside=glui_labels->add_checkbox_to_panel(PANEL_tick1a, "inside", &glui_tick_inside, LABELS_tick_inside, LabelsCB);
  glui_labels->add_column_to_panel(PANEL_tick1a, false);
  CHECKBOX_ticks_outside=glui_labels->add_checkbox_to_panel(PANEL_tick1a, "outside", &glui_tick_outside, LABELS_tick_outside, LabelsCB);
  glui_labels->add_column_to_panel(PANEL_tick1a, false);
  SPINNER_ntick_decimals = glui_labels->add_spinner_to_panel(PANEL_tick1a, _("decimals"), GLUI_SPINNER_INT, &ntick_decimals);
  SPINNER_ntick_decimals->set_int_limits(0, 6, GLUI_LIMIT_CLAMP);
  LabelsCB(LABELS_tick_inside);
  LabelsCB(LABELS_tick_outside);

  PANEL_tick1b = glui_labels->add_panel_to_panel(PANEL_tick1,"",false);
  CHECKBOX_tick_auto=glui_labels->add_checkbox_to_panel(PANEL_tick1b,_("Auto place"),&auto_user_tick_placement,LABELS_ticks,LabelsCB);
  glui_labels->add_column_to_panel(PANEL_tick1b,false);
  CHECKBOX_user_ticks_show_x=glui_labels->add_checkbox_to_panel(PANEL_tick1b,"x",&user_tick_show_x);
  glui_labels->add_column_to_panel(PANEL_tick1b,false);
  CHECKBOX_user_ticks_show_y=glui_labels->add_checkbox_to_panel(PANEL_tick1b,"y",&user_tick_show_y);
  glui_labels->add_column_to_panel(PANEL_tick1b,false);
  CHECKBOX_user_ticks_show_z=glui_labels->add_checkbox_to_panel(PANEL_tick1b,"z",&user_tick_show_z);
  LabelsCB(LABELS_ticks);
  glui_labels->add_column_to_panel(PANEL_tick1b, false);
  SPINNER_subtick = glui_labels->add_spinner_to_panel(PANEL_tick1b, _("sub-intervals"), GLUI_SPINNER_INT, &user_tick_sub);
  SPINNER_subtick->set_int_limits(1, 10, GLUI_LIMIT_CLAMP);

  PANEL_tick2 = glui_labels->add_panel_to_panel(ROLLOUT_user_tick,_("Parameters"),true);
  glui_labels->add_statictext_to_panel(PANEL_tick2,"                    x");
  SPINNER_tick_x0=glui_labels->add_spinner_to_panel(PANEL_tick2,_("origin"),GLUI_SPINNER_FLOAT,user_tick_origin);
  SPINNER_tick_xmin=glui_labels->add_spinner_to_panel(PANEL_tick2,_("Min"),GLUI_SPINNER_FLOAT,user_tick_min);
  SPINNER_tick_xmax=glui_labels->add_spinner_to_panel(PANEL_tick2,_("Max"),GLUI_SPINNER_FLOAT,user_tick_max);
  SPINNER_tick_dx0=glui_labels->add_spinner_to_panel(PANEL_tick2,_("Step"),GLUI_SPINNER_FLOAT,user_tick_step);

  glui_labels->add_column_to_panel(PANEL_tick2,false);

  glui_labels->add_statictext_to_panel(PANEL_tick2,"                    y");
  SPINNER_tick_y0=glui_labels->add_spinner_to_panel(PANEL_tick2,"",GLUI_SPINNER_FLOAT,user_tick_origin+1);
  SPINNER_tick_ymin=glui_labels->add_spinner_to_panel(PANEL_tick2,"",GLUI_SPINNER_FLOAT,user_tick_min+1);
  SPINNER_tick_ymax=glui_labels->add_spinner_to_panel(PANEL_tick2,"",GLUI_SPINNER_FLOAT,user_tick_max+1);
  SPINNER_tick_dy0=glui_labels->add_spinner_to_panel(PANEL_tick2,"",GLUI_SPINNER_FLOAT,user_tick_step+1);

  glui_labels->add_column_to_panel(PANEL_tick2,false);

  glui_labels->add_statictext_to_panel(PANEL_tick2,"                    z");
  SPINNER_tick_z0=glui_labels->add_spinner_to_panel(PANEL_tick2,"",GLUI_SPINNER_FLOAT,user_tick_origin+2);
  SPINNER_tick_zmin=glui_labels->add_spinner_to_panel(PANEL_tick2,"",GLUI_SPINNER_FLOAT,user_tick_min+2);
  SPINNER_tick_zmax=glui_labels->add_spinner_to_panel(PANEL_tick2,"",GLUI_SPINNER_FLOAT,user_tick_max+2);
  SPINNER_tick_dz0=glui_labels->add_spinner_to_panel(PANEL_tick2,"",GLUI_SPINNER_FLOAT,user_tick_step+2);

  // -------------- User labels -------------------

  gl=&LABEL_local;
  ROLLOUT_user_labels = glui_labels->add_rollout("Labels + Ticks",false,LABELS_ROLLOUT,DisplayRolloutCB);
  INSERT_ROLLOUT(ROLLOUT_user_labels, glui_labels);
  ADDPROCINFO(displayprocinfo, ndisplayprocinfo, ROLLOUT_user_labels, LABELS_ROLLOUT, glui_labels);

  PANEL_LB_panel1 = glui_labels->add_panel_to_panel(ROLLOUT_user_labels,"",GLUI_PANEL_NONE);


  PANEL_LB_panel3 = glui_labels->add_panel_to_panel(ROLLOUT_user_labels,_("Labels"));

  CHECKBOX_LB_visLabels=glui_labels->add_checkbox_to_panel(PANEL_LB_panel3,_("Show labels"),&visLabels,LB_VISLABELS,TextLabelsCB);

  PANEL_LB_panel4 = glui_labels->add_panel_to_panel(PANEL_LB_panel3,"",GLUI_PANEL_NONE);
  BUTTON_LB_label_add=glui_labels->add_button_to_panel(PANEL_LB_panel4,"Add",LB_ADD,TextLabelsCB);
  glui_labels->add_column_to_panel(PANEL_LB_panel4,false);
  BUTTON_LB_label_delete=glui_labels->add_button_to_panel(PANEL_LB_panel4,_("Delete"),LB_DELETE,TextLabelsCB);

  LIST_LB_labels=glui_labels->add_listbox_to_panel(PANEL_LB_panel3,_("Select"),&label_list_index,LB_LIST,TextLabelsCB);
  {
    labeldata *thislabel;
    int count=0;

    for(thislabel=label_first_ptr->next;thislabel->next!=NULL;thislabel=thislabel->next){
      if(thislabel->labeltype==TYPE_SMV){
        thislabel->glui_id=-1;
        continue;
      }
      thislabel->glui_id=count;
      LIST_LB_labels->add_item(count++,thislabel->name);
    }
  }
  PANEL_LB_panel2 = glui_labels->add_panel_to_panel(PANEL_LB_panel3,"",GLUI_PANEL_NONE);
  EDIT_LB_label_string=glui_labels->add_edittext_to_panel(PANEL_LB_panel2,_("Edit:"),GLUI_EDITTEXT_TEXT,gl->name,LB_UPDATE,TextLabelsCB);
  glui_labels->add_column_to_panel(PANEL_LB_panel2,false);
  BUTTON_LB_label_update=glui_labels->add_button_to_panel(PANEL_LB_panel2,_("Update"),LB_UPDATE,TextLabelsCB);

  PANEL_LB_panel6 = glui_labels->add_panel_to_panel(PANEL_LB_panel3,"",GLUI_PANEL_NONE);
  BUTTON_LB_label_previous=glui_labels->add_button_to_panel(PANEL_LB_panel6,_("Previous"),LB_PREVIOUS,TextLabelsCB);
  glui_labels->add_column_to_panel(PANEL_LB_panel6,false);
  BUTTON_LB_label_next=glui_labels->add_button_to_panel(PANEL_LB_panel6,_("Next"),LB_NEXT,TextLabelsCB);

  PANEL_LB_panel5 = glui_labels->add_panel_to_panel(ROLLOUT_user_labels,"",GLUI_PANEL_NONE);
  PANEL_LB_position=glui_labels->add_panel_to_panel(PANEL_LB_panel5,_("position"));
  SPINNER_LB_x=glui_labels->add_spinner_to_panel(PANEL_LB_position,"x",GLUI_SPINNER_FLOAT,gl->xyz,LB_XYZ,TextLabelsCB);
  SPINNER_LB_y=glui_labels->add_spinner_to_panel(PANEL_LB_position,"y",GLUI_SPINNER_FLOAT,gl->xyz+1,LB_XYZ,TextLabelsCB);
  SPINNER_LB_z=glui_labels->add_spinner_to_panel(PANEL_LB_position,"z",GLUI_SPINNER_FLOAT,gl->xyz+2,LB_XYZ,TextLabelsCB);
  {
    float xmin, ymin, zmin, xmax, ymax, zmax;

    xmin = xbar0ORIG - 0.25*(xbarORIG-xbar0ORIG);
    xmax = xbarORIG + 0.25*(xbarORIG-xbar0ORIG);
    ymin = ybar0ORIG - 0.25*(ybarORIG-ybar0ORIG);
    ymax = ybarORIG + 0.25*(ybarORIG-ybar0ORIG);
    zmin = zbar0ORIG - 0.25*(zbarORIG-zbar0ORIG);
    zmax = zbarORIG + 0.25*(zbarORIG-zbar0ORIG);
    SPINNER_LB_x->set_float_limits(xmin,xmax);
    SPINNER_LB_y->set_float_limits(ymin,ymax);
    SPINNER_LB_z->set_float_limits(zmin,zmax);

  }

  glui_labels->add_column_to_panel(PANEL_LB_panel5,false);
  PANEL_LB_time=glui_labels->add_panel_to_panel(PANEL_LB_panel5,_("time"));
  SPINNER_LB_time_start=glui_labels->add_spinner_to_panel(PANEL_LB_time,_("start"),GLUI_SPINNER_FLOAT,gl->tstart_stop,LB_STARTSTOP,TextLabelsCB);
  SPINNER_LB_time_stop=glui_labels->add_spinner_to_panel(PANEL_LB_time,_("stop"),GLUI_SPINNER_FLOAT,gl->tstart_stop+1,LB_STARTSTOP,TextLabelsCB);
  CHECKBOX_LB_label_show_always=glui_labels->add_checkbox_to_panel(PANEL_LB_time,_("Show always"),&gl->show_always,LB_SHOWALWAYS,TextLabelsCB);

  PANEL_LB_color=glui_labels->add_panel_to_panel(ROLLOUT_user_labels,_("color"));
  SPINNER_LB_red=glui_labels->add_spinner_to_panel(PANEL_LB_color,_("red"),GLUI_SPINNER_INT,gl->rgb,LB_RGB,TextLabelsCB);
  SPINNER_LB_green=glui_labels->add_spinner_to_panel(PANEL_LB_color,_("green"),GLUI_SPINNER_INT,gl->rgb+1,LB_RGB,TextLabelsCB);
  SPINNER_LB_blue=glui_labels->add_spinner_to_panel(PANEL_LB_color,_("blue"),GLUI_SPINNER_INT,gl->rgb+2,LB_RGB,TextLabelsCB);
  SPINNER_LB_red->set_int_limits(0,255);
  SPINNER_LB_green->set_int_limits(0,255);
  SPINNER_LB_blue->set_int_limits(0,255);
  CHECKBOX_LB_label_use_foreground=glui_labels->add_checkbox_to_panel(PANEL_LB_color,_("Use foreground color"),&gl->useforegroundcolor,LB_FOREGROUND,TextLabelsCB);

  ROLLOUT_LB_tick0 = glui_labels->add_rollout_to_panel(ROLLOUT_user_labels, "tick",false);
  INSERT_ROLLOUT(ROLLOUT_LB_tick0, glui_labels);
  CHECKBOX_labels_showtick = glui_labels->add_checkbox_to_panel(ROLLOUT_LB_tick0, "show tick", &gl->show_tick, LB_SHOW_TICK, TextLabelsCB);
  PANEL_LB_tick = glui_labels->add_panel_to_panel(ROLLOUT_LB_tick0, "",GLUI_PANEL_NONE);
  SPINNER_LB_tick_xbeg = glui_labels->add_spinner_to_panel(PANEL_LB_tick, "x", GLUI_SPINNER_FLOAT, gl->tick_begin, LB_TICK_XYZ, TextLabelsCB);
  SPINNER_LB_tick_ybeg = glui_labels->add_spinner_to_panel(PANEL_LB_tick, "y", GLUI_SPINNER_FLOAT, gl->tick_begin+1, LB_TICK_XYZ, TextLabelsCB);
  SPINNER_LB_tick_zbeg = glui_labels->add_spinner_to_panel(PANEL_LB_tick, "z", GLUI_SPINNER_FLOAT, gl->tick_begin+2, LB_TICK_XYZ, TextLabelsCB);
  glui_labels->add_column_to_panel(PANEL_LB_tick, false);
  SPINNER_LB_tick_xdir = glui_labels->add_spinner_to_panel(PANEL_LB_tick, "dx", GLUI_SPINNER_FLOAT, gl->tick_direction, LB_TICK_XYZ, TextLabelsCB);
  SPINNER_LB_tick_ydir = glui_labels->add_spinner_to_panel(PANEL_LB_tick, "dy", GLUI_SPINNER_FLOAT, gl->tick_direction+1, LB_TICK_XYZ, TextLabelsCB);
  SPINNER_LB_tick_zdir = glui_labels->add_spinner_to_panel(PANEL_LB_tick, "dz", GLUI_SPINNER_FLOAT, gl->tick_direction+2, LB_TICK_XYZ, TextLabelsCB);

  TextLabelsCB(LB_LIST);

  // --------------

  PANEL_label2 = glui_labels->add_panel("",false);
  glui_labels->add_column_to_panel(PANEL_label2,false);

  BUTTON_label_3=glui_labels->add_button_to_panel(PANEL_label2,_("Save settings"),SAVE_SETTINGS_DISPLAY,LabelsCB);
  glui_labels->add_column_to_panel(PANEL_label2,false);

  BUTTON_label_4=glui_labels->add_button_to_panel(PANEL_label2,_("Close"),LABELS_close,LabelsCB);
#ifdef pp_CLOSEOFF
  BUTTON_label_4->disable();
#endif

  glui_labels->set_main_gfx_window( main_window );
}

/* ------------------ HideGluiDisplay ------------------------ */

extern "C" void HideGluiDisplay(void){
  CloseRollouts(glui_labels);
}

/* ------------------ ShowGluiDisplay ------------------------ */

extern "C" void ShowGluiDisplay(int menu_id){
  if(glui_labels!=NULL)glui_labels->show();
  switch(menu_id){
  case DIALOG_DISPLAY:
    DisplayRolloutCB(GENERAL_ROLLOUT);
    break;
  case DIALOG_FONTS:
    DisplayRolloutCB(FONTS_ROLLOUT);
    break;
  case DIALOG_TICKS:
    DisplayRolloutCB(TICKS_ROLLOUT);
    break;
  case DIALOG_LABELS:
    DisplayRolloutCB(LABELS_ROLLOUT);
    break;
  default:
    ASSERT(0);
    break;
  }
}

/* ------------------ UpdateColorbarControls ------------------------ */

extern "C" void UpdateColorbarControls(void){
  if(CHECKBOX_visColorbarVertical!=NULL&&CHECKBOX_visColorbarVertical->get_int_val() != visColorbarVertical)CHECKBOX_visColorbarVertical->set_int_val(visColorbarVertical);
  if(CHECKBOX_visColorbarHorizontal!=NULL&&CHECKBOX_visColorbarHorizontal->get_int_val() != visColorbarHorizontal)CHECKBOX_visColorbarHorizontal->set_int_val(visColorbarHorizontal);
}
/* ------------------ LabelsCB ------------------------ */

extern "C" void LabelsCB(int var){
  updatemenu=1;
  switch(var){
#ifdef pp_REFRESH
    case LABELS_REFRESH_RATE:
      if(glui_refresh_rate>0){
        refresh_interval = 1000/(float)glui_refresh_rate;
        if(glui_refresh_rate_old==0){
          PeriodicRefresh(refresh_interval);
          GLUTPOSTREDISPLAY;
        }
      }
      glui_refresh_rate_old = glui_refresh_rate;
      break;
#endif
  case LABELS_colorbar_shift:
    UpdateRGBColors(colorbar_select_index);
    break;
 // vis_colorbar      state
 //    0/COLORBAR_HIDDEN               hidden
 //    1/COLORBAR_SHOW_VERTICAL        vertical
 //    2->max/COLORBAR_SHOW_HORIZONTAL horizontal
  case LABELS_vcolorbar:
  case LABELS_hcolorbar:
    if(var==LABELS_vcolorbar){
      if (visColorbarVertical == 1)visColorbarHorizontal = 0;
    }
    else{
      if (visColorbarHorizontal == 1)visColorbarVertical = 0;
    }
    UpdateColorbarControls();
    UpdateColorbarControls2();
    vis_colorbar = GetColorbarState();
    break;
  case LABELS_tick_inside:
  case LABELS_tick_outside:
    if(var==LABELS_tick_inside){
      glui_tick_outside = 1 - glui_tick_inside;
      CHECKBOX_ticks_outside->set_int_val(glui_tick_outside);
    }
    if(var==LABELS_tick_outside){
      glui_tick_inside = 1 - glui_tick_outside;
      CHECKBOX_ticks_inside->set_int_val(glui_tick_inside);
    }
    user_tick_direction=1.0;
    if(glui_tick_inside==1)user_tick_direction=-1.0;
    break;
  case APPLY_VENTOFFSET:
    UpdateVentOffset();
    updatefaces=1;
    break;
  case FLIP:
      colorbar_flip = 1 - colorbar_flip;
      ColorbarMenu(COLORBAR_FLIP);
      break;
  case LABELS_hide_overlaps:
    updatefacelists=1;
    updatehiddenfaces=1;
    UpdateHiddenFaces();
    glutPostRedisplay();
    break;
#ifdef pp_BETA
  case LABELS_drawface:
    /*
    if(use_new_drawface==1){
      CHECKBOX_cullgeom->enable();
      if(cullgeom==1){
        SPINNER_cullgeom_portsize->enable();
      }
      else{
        SPINNER_cullgeom_portsize->disable();
      }
    }
    else{
      CHECKBOX_cullgeom->disable();
      SPINNER_cullgeom_portsize->disable();
    }
    update_initcullgeom=1;
    SetCullVis();
    */
    updatefacelists=1;
    break;
#endif

  case CB_USE_LIGHTING:
  case LABELS_shownorth:
  case LABELS_version:
  case LABELS_meshlabel:
  case LABELS_label:
  case LABELS_HMS:
  case LABELS_transparent:
  case FIRECUTOFF_label:
    break;
  case LABELS_usertick:
    CHECKBOX_visUSERticks2->set_int_val(visUSERticks);
    break;
  case LABELS_usertick2:
    CHECKBOX_visUSERticks->set_int_val(visUSERticks);
    if(visUSERticks==1)ROLLOUT_user_tick->open();
    break;
  case SAVE_SETTINGS_DISPLAY:
    WriteIni(LOCAL_INI,NULL);
    break;
  case LABELS_showall:
    LabelMenu(MENU_LABEL_ShowAll);
    break;
  case LABELS_hideall:
    LabelMenu(MENU_LABEL_HideAll);
    break;
  case LABELS_flip:
    background_flip = 1 - background_flip;
    ShowHideMenu(MENU_SHOWHIDE_FLIP);
    break;
  case LABELS_shade:
    InitRGB();
    break;
  case LABELS_shadedata:
    if(setbwdata==1){
      colorbartype_save=colorbartype;
      ColorbarMenu(bw_colorbar_index);
    }
    else{
      ColorbarMenu(colorbartype_save);
    }
    break;
  case LABELS_close:
    HideGluiDisplay();
    break;
  case LABELS_fontsize:
    FontMenu(fontindex);
    break;
  case FRAME_label:
    visFramelabel=1-visFramelabel;
    LabelMenu(MENU_LABEL_framerate);
    break;
  case HRR_label:
    visHRRlabel=1-visHRRlabel;
    LabelMenu(MENU_LABEL_hrr);
    break;
  case LABELS_ticks:
    if(auto_user_tick_placement==1){
      CHECKBOX_user_ticks_show_x->disable();
      CHECKBOX_user_ticks_show_y->disable();
      CHECKBOX_user_ticks_show_z->disable();
    }
    else{
      CHECKBOX_user_ticks_show_x->enable();
      CHECKBOX_user_ticks_show_y->enable();
      CHECKBOX_user_ticks_show_z->enable();
    }
    break;
  default:
    ASSERT(FFALSE);
  }
}

/* ------------------ SetLabelControls ------------------------ */

  extern "C" void SetLabelControls(){

  if(CHECKBOX_LB_visLabels!=NULL)CHECKBOX_LB_visLabels->set_int_val(visLabels);
  if(CHECKBOX_visUSERticks!=NULL)CHECKBOX_visUSERticks->set_int_val(visUSERticks);
  if(CHECKBOX_labels_hrrlabel!=NULL)CHECKBOX_labels_hrrlabel->set_int_val(visHRRlabel);
  if(CHECKBOX_labels_firecutoff!=NULL)CHECKBOX_labels_firecutoff->set_int_val(show_firecutoff);
  if(CHECKBOX_labels_title!=NULL)CHECKBOX_labels_title->set_int_val(vis_title_smv_version);
  if(CHECKBOX_labels_fds_title!=NULL)CHECKBOX_labels_fds_title->set_int_val(vis_title_fds);
  if(CHECKBOX_labels_chid!=NULL)CHECKBOX_labels_chid->set_int_val(vis_title_CHID);
  if(CHECKBOX_visColorbarVertical!=NULL)CHECKBOX_visColorbarVertical->set_int_val(visColorbarVertical);
  if(CHECKBOX_labels_timebar!=NULL)CHECKBOX_labels_timebar->set_int_val(visTimebar);
  if(CHECKBOX_labels_timelabel!=NULL)CHECKBOX_labels_timelabel->set_int_val(visTimelabel);
  if(CHECKBOX_labels_framelabel!=NULL)CHECKBOX_labels_framelabel->set_int_val(visFramelabel);
  if(CHECKBOX_labels_ticks!=NULL)CHECKBOX_labels_ticks->set_int_val(visFDSticks);
  if(CHECKBOX_labels_axis!=NULL)CHECKBOX_labels_axis->set_int_val(visaxislabels);
  if(CHECKBOX_labels_framerate!=NULL)CHECKBOX_labels_framerate->set_int_val(visFramerate);
  if(CHECKBOX_labels_average!=NULL)CHECKBOX_labels_average->set_int_val(vis_slice_average);
#ifdef pp_memstatus
  if(CHECKBOX_labels_availmemory!=NULL)CHECKBOX_labels_availmemory->set_int_val(visAvailmemory);
#endif
  if(CHECKBOX_labels_labels!=NULL)CHECKBOX_labels_labels->set_int_val(visLabels);

  if(CHECKBOX_labels_flip!=NULL)CHECKBOX_labels_flip->set_int_val(background_flip);
  if(RADIO_fontsize != NULL)RADIO_fontsize->set_int_val(fontindex);
  if(CHECKBOX_labels_hms!=NULL)CHECKBOX_labels_hms->set_int_val(vishmsTimelabel);
  if(CHECKBOX_labels_gridloc!=NULL)CHECKBOX_labels_gridloc->set_int_val(visgridloc);
  if(CHECKBOX_labels_version!=NULL)CHECKBOX_labels_version->set_int_val(vis_title_gversion);
  if(CHECKBOX_labels_meshlabel!=NULL)CHECKBOX_labels_meshlabel->set_int_val(visMeshlabel);
  if(CHECKBOX_visUSERticks2!=NULL)CHECKBOX_visUSERticks2->set_int_val(visUSERticks);
  SetLabelControls2();

}



