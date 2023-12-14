-- @module 'iniparser'
local iniparser = {}

local inioptions = require "inioptions"
local lpeg = require "lpeg"
lpeg.locale(lpeg)

if smokeviewEmbedded then execute = true else execute = false end

local function buildOpt(opt)
    local option = {name = opt[1], argLines = opt[2]}
    -- printOption(option)
    -- local execute = false
    option = inioptions.validate(option, execute)
    return option
end

local function printOption(opt)
    print("Option")
    io.write("  Name:\t" .. opt.name .. "\n")
    io.write("  Arguments:\n")
    for ki,vi in pairs(opt.argLines) do
        print("    line: " .. ki)
        for k,v in pairs(vi) do
            print("      " .. k .. ": " .. v)
        end
    end
    -- for key,val in pairs(inst.args) do
    --     io.write(val .. ", ")
    -- end
    -- io.write("]\n")
end

local whitespace = lpeg.space^0
local integer = lpeg.S("-+")^-1 * lpeg.R("09")^1 / tonumber
local float = lpeg.S("-+")^-1 * lpeg.R("09")^1 * lpeg.P(".")^0 * lpeg.R("09")^0
            / tonumber
local stringChar = lpeg.alnum + lpeg.punct -- the chars that are valid in a string
local string = lpeg.C(stringChar^1)
local filepath = string
local eol = lpeg.P("\n") + lpeg.P("\r\n")
local optionNameChar = lpeg.alnum + lpeg.S("_")
local optionName = lpeg.C(optionNameChar^1) * eol
-- rgb = lpeg.R(float) * lpeg.space^1 * lpeg.R(float) * lpeg.space^1 * lpeg.R(float)
-- command = lpeg.C(lpeg.alnum^1)
local comment = lpeg.space^0 * lpeg.P(":")
    * lpeg.P(lpeg.alnum + lpeg.punct + lpeg.S(" \t"))^0
    * #eol
local rootComment = lpeg.space^0 * lpeg.S("#-*(")
    * lpeg.P(lpeg.alnum + lpeg.punct + lpeg.S(" \t"))^0
    * eol
local argument = float + integer + string + lpeg.S(" \t")^1 -- + comment +
    -- lpeg.P(eol * (#(lpeg.space) + eol * #comment))
local argumentLine = lpeg.S(" \t")^1 * lpeg.Ct(argument^0) * comment^0 * eol^-1
local emptyLine = lpeg.S(" \t")^0 * eol
local junkLine = emptyLine + rootComment
local option = junkLine^0 * lpeg.Ct(optionName * lpeg.Ct(argumentLine^0)) / buildOpt
local iniFile = lpeg.Ct(option^0) * junkLine^0 * -lpeg.P(1)
-- arguments = lpeg.Ct(argument^0) * eol^-1
-- instruction = lpeg.Ct(command * arguments) / buildInst
-- script = lpeg.Ct(instruction^0)

-- print("OPTION NAME")
-- exampleOptionName = "AMBIENTLIGHT\n 0.600000 0.600000 0.600000\n 0.800000 0.700000 0.900000\n"
-- testOption = option:match(exampleOption)
-- printOption(testOption)
-- print("OPTION")
-- exampleOption = "AMBIENTLIGHT\n 0.600000 0.600000 0.600000\n 0.800000 0.700000 0.900000\n"
-- testOption = option:match(exampleOption)
-- printOption(testOption)

-- print("ARGUMENT LINE")
-- exampleArgumentLine = " 0.600000 0.600000 0.600000 : grey\n"
-- testArgumentLine = argumentLine:match(exampleArgumentLine)
-- for k,v in pairs(testArgumentLine) do
--     print(testArgumentLine[k])
-- end

local function parseINI(filepath)
    print("parsing:", filepath)
    local f,err = io.open(filepath, "r")
    if f == nil then
        error(err,1)
    end
    local input = f:read("*all")
    local parsedIniFile = iniFile:match(input)
    io.close()
    print(parsedIniFile)
end

local function test()
    parseINI("test.ini")
end

return iniparser
-- print(emptyLine:match(" \n    \n\n    \r\n"))
-- test()
