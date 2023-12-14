--- @module 'plot'
local plot = {}

local gp = require('gnuplot')
local lfs = require('lfs')

function plot.createDV(cols, colXIndex, colYIndex, name)
    return { x = cols[colXIndex], y = cols[colYIndex], name = name }
end

function plot.addDVs(dvs, newName)
    local newDV = {}
    newDV.name = newName
    newDV.x = { values = {} }
    newDV.y = { values = {} }
    newDV.x.units = dvs[1].x.units
    newDV.x.name = dvs[1].x.name
    newDV.y.units = dvs[1].y.units
    newDV.y.name = dvs[1].y.name
    for i, v in ipairs(dvs[1].x.values) do
        newDV.x.values[i] = v
        local yval = 0
        for j, b in ipairs(dvs) do
            yval = yval + b.y.values[i]
        end
        newDV.y.values[i] = yval
    end
    return newDV
end

function plot.negateDV(dv)
    local newDV = {
        name = dv.name,
        x = { name = dv.x.name, units = dv.x.units, values = dv.x.values },
        y = { name = dv.y.name, units = dv.y.units, values = {} }
    }
    for i, v in ipairs(dv.y.values) do
        newDV.y.values[i] = -1 * dv.y.values[i]
    end
    return newDV
end

local function abs(n)
    if (n < 0)
    then
        return -n
    else
        return n
    end
end

function plot.absDV(dv)
    local newDV = {
        name = dv.name,
        x = { name = dv.x.name, units = dv.x.units, values = dv.x.values },
        y = { name = dv.y.name, units = dv.y.units, values = {} }
    }
    for i, v in ipairs(dv.y.values) do
        newDV.y.values[i] = abs(dv.y.values[i])
    end
    return newDV
end

local function createDVNamed(cols, colXName, colYName, name)
    local xVector
    local yVector
    -- Find the index of the x vector.
    for i, v in ipairs(cols) do
        if (v.name == (colXName)) then
            xVector = v
            break
        end
    end
    if not xVector then
        print("no value for: " .. colYName)
        return nil
    end
    -- Find the index of the y vector.
    for i, v in ipairs(cols) do
        if (v.name == (colYName)) then
            yVector = v
            break
        end
    end
    if not yVector then
        print("no value for: " .. colYName)
        return nil
    end
    return { x = xVector, y = yVector, name = name }
end

function plot.DV(dir, dvs, title, opts)
    if type(dvs) ~= "table" then
        error("dvs must be a table")
    elseif dvs.x and dvs.y then
        plot.MultiDV(dir, { dvs }, title, opts)
    else
        plot.MultiDV(dir, dvs, title, opts)
    end
end

local function splitpath(inputstr, sep)
    if sep == nil then
        sep = "%s"
    end
    local t = {}
    for str in string.gmatch(inputstr, "([^" .. sep .. "]+)") do
        table.insert(t, str)
    end
    return t
end

local function recursive_mkdir(path)
    local sep = "/"
    local path_elems = splitpath(path, sep)
    local p = ""
    for _, elem in ipairs(path_elems) do
        p = p .. elem .. sep
        lfs.mkdir(p)
    end
end

function plot.MultiDV(dir, dvs, title, opts)
    recursive_mkdir(dir)
    local g = gp {
        -- All optional, with sane defaults.
        width  = 1600,
        height = 1000,
        xlabel = dvs[1].x.name .. " (" .. dvs[1].x.units .. ")",
        ylabel = dvs[1].y.name .. " (" .. dvs[1].y.units .. ")",
        key    = "top left",
        title  = title:gsub("_", "\\\\_"),
        -- consts = {
        --     gamma = 2.5
        -- },

        data   = {}

    }
    if opts then
        for k, v in pairs(opts) do
            g[k] = v
        end
    end
    if (not opts) or (not opts.fname) then
        g.fname = "Arial"
    end
    if (not opts) or (not opts.fsize) then
        g.fsize = 12
    end
    for i, dv in ipairs(dvs) do
        local arr = { -- plot from an 'array-like' thing in memory. Could be a
            -- numlua matrix, for example.
            {
                dv.x.values, -- x
                dv.y.values  -- y
            },

            title = dv.y.name, -- optional
            using = { 1, 2 }   -- optional
        }
        if dv.name then arr.title = dv.name else arr.title = dv.y.name end
        if (dv.with) then arr.with = dv.with else arr.with = 'linespoints' end
        g.data[i] = gp.array(arr)
    end
    g:plot(dir .. "/" .. title .. '.png')
end

local function stdGrowthRate(alpha, t)
    if (t <= 0) then
        return 0
    else
        return alpha * t ^ 2
    end
end

local slowAlpha = 1000 / 600 ^ 2;
local mediumAlpha = 1000 / 300 ^ 2;
local fastAlpha = 1000 / 150 ^ 2;
local ultrafastAlpha = 1000 / 75 ^ 2;

local slowColour = '#008000'
local mediumColour = '#FF0000'
local fastColour = '#00BFBF'
local ultrafastColour = '#BF00BF'

local function createStdHRRCurves(dv, offset)
    if not offset then offset = 0 end
    local maxHRR = 0
    print(dv)
    for i, v in ipairs(dv.y.values) do
        if v > maxHRR then maxHRR = v end
    end
    if maxHRR == 0 then maxHRR = 1 end
    local slowDV = {
        name = "Slow HRR",
        x = { name = "Time", units = "s", values = {} },
        y = { name = "Slow HRR", units = "kW", values = {} }
    }
    local mediumDV = {
        name = "Medium HRR",
        x = { name = "Time", units = "s", values = {} },
        y = { name = "Medium HRR", units = "kW", values = {} }
    }
    local fastDV = {
        name = "Fast HRR",
        x = { name = "Time", units = "s", values = {} },
        y = { name = "Fast HRR", units = "kW", values = {} }
    }
    local ultrafastDV = {
        name = "Ultrafast HRR",
        x = { name = "Time", units = "s", values = {} },
        y = { name = "Ultrafast HRR", units = "kW", values = {} }
    }
    for i, v in ipairs(dv.x.values) do
        local slowVal = stdGrowthRate(slowAlpha, v - offset)
        local mediumVal = stdGrowthRate(mediumAlpha, v - offset)
        local fastVal = stdGrowthRate(fastAlpha, v - offset)
        local ultrafastVal = stdGrowthRate(ultrafastAlpha, v - offset)
        if slowVal < (1.1 * maxHRR) then
            slowDV.x.values[i] = v
            slowDV.y.values[i] = slowVal
        end
        if mediumVal < (1.1 * maxHRR) then
            mediumDV.x.values[i] = v
            mediumDV.y.values[i] = mediumVal
        end
        if fastVal < (1.1 * maxHRR) then
            fastDV.x.values[i] = v
            fastDV.y.values[i] = fastVal
        end
        if ultrafastVal < (1.1 * maxHRR) then
            ultrafastDV.x.values[i] = v
            ultrafastDV.y.values[i] = ultrafastVal
        end
    end
    slowDV.with = string.format('lines dashtype 2 lt rgb \"%s\"', slowColour)
    mediumDV.with = string.format('lines dashtype 2 lt rgb \"%s\"', mediumColour)
    fastDV.with = string.format('lines dashtype 2 lt rgb \"%s\"', fastColour)
    ultrafastDV.with = string.format('lines dashtype 2 lt rgb \"%s\"', ultrafastColour)
    return slowDV, mediumDV, fastDV, ultrafastDV
end

function plot.plotHRRDV(plotDir, hrrDV, name, config)
    local vecs
    local offset
    if config and config.offset then
        offset = config.offset
    else
        offset = 0
    end
    if hrrDV.x and hrrDV.y then
        print(hrrDV.name)
        local slowDV, mediumDV, fastDV, ultrafastDV = createStdHRRCurves(hrrDV, offset)
        vecs = { hrrDV, slowDV, mediumDV, fastDV, ultrafastDV }
    else
        -- TODO: find the best set of x points from each HRR DV, instead of using
        -- hrrDV[1]
        print(hrrDV[1].name)
        local slowDV, mediumDV, fastDV, ultrafastDV = createStdHRRCurves(hrrDV[1], offset)
        vecs = hrrDV
        for i, v in ipairs({ slowDV, mediumDV, fastDV, ultrafastDV }) do
            print(i, v.name)
            vecs[#vecs + 1] = v
        end
        for i, v in ipairs(vecs) do
            print(i, v.name)
        end
    end
    do
        local filteredVec = smv.deepCopy(hrrDV)
        plot.wma(filteredVec, 20)
        filteredVec.name = "Time-Averaged (WMA)"
        vecs[#vecs + 1] = filteredVec
    end
    return plot.DV(plotDir, vecs, name, config)
end

function plot.printVec(vec)
    print(string.format("%s %s (%s) - %s (%s)", vec.name, vec.x.name,
        vec.x.units, vec.y.name, vec.y.units))
    for i, v in ipairs(vec.x.values) do
        print(string.format("  x: %.2f y: %.2f", vec.x.values[i], vec.y.values[i]))
    end
end

function plot.sumVec(dvs)
    local resultVec
    for i = 1, #dvs do
        local vec = dvs[i]
        if vec then
            if not resultVec then
                resultVec = vec
            else
                resultVec = plot.addDVs({ resultVec, vec }, resultVec.name)
            end
        end
    end
    return resultVec
end

function plot.avgVec(dv, window)
    for i, v in ipairs(dv.y.values) do
        local val = 0
        local n = 0
        for j = 0, window do
            local l = dv.y.values[i + j]
            if l == nil then break end
            val = val + l
            n = n + 1
        end
        dv.y.values[i] = val / n
    end
    return dv
end

-- Weighted moving average
function plot.wma(dv, window)
    if #dv.y.values <= 1 then
        -- The weighted average of an empty vector or a vector that has a
        -- single element is just the same vector
        error("cannot average empty vector")
    end
    for i, v in ipairs(dv.y.values) do
        local val = 0
        local n = 0
        -- The total sum
        local sum = 0;
        -- First the actual value is fully weighted
        sum = sum + v * window
        local totalWeight = window
        for j = 1, window do
            local weight = window - j
            local valueBehind = dv.y.values[i - j]
            if valueBehind == nil then
                -- If the window covers an area "before" before the start of the
                -- vector, just use the first value. We know this exists as th
                -- vector is not empty.
                valueBehind = dv.y.values[1]
            end
            local valueAhead = dv.y.values[i + j]
            if valueAhead == nil then
                -- If the window covers an area "after" before the end of the
                -- vector, just use the last value. We know this exists as th
                -- vector is not empty.
                valueAhead = dv.y.values[#dv.y.values]
            end
            sum = sum + valueBehind * weight
            sum = sum + valueAhead * weight
            totalWeight = totalWeight + weight * 2
        end
        dv.y.values[i] = sum / totalWeight
    end
    return dv
end

function plot.avgDVs(dvs, newName)
    local newDV = {}
    newDV.name = newName
    newDV.x = { values = {} }
    newDV.y = { values = {} }
    newDV.x.units = dvs[1].x.units
    newDV.x.name = dvs[1].x.name
    newDV.y.units = dvs[1].y.units
    newDV.y.name = dvs[1].y.name
    for i, v in ipairs(dvs[1].x.values) do
        newDV.x.values[i] = v
        local yval = 0
        for j, b in ipairs(dvs) do
            yval = yval + b.y.values[i]
        end
        newDV.y.values[i] = yval / (#dvs)
    end
    return newDV
end

function plot.convert(dv)
    local newDV = {
        x = {
            name = dv.NameX,
            units = dv.UnitsX,
            values = {},
        },
        y = {
            name = dv.NameY,
            units = dv.UnitsY,
            values = {},
        }
    }
    for i, v in ipairs(dv.Values) do
        newDV.x.values[i] = v.x
        newDV.y.values[i] = v.y
    end
    return newDV
end

return plot
