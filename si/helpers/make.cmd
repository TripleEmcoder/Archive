@echo off
msbuild helpers.sln
cmd /C downloads
cmd /C properties
cmd /C plants
cmd /C questions
