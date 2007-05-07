@echo off
dot\dot.exe -Tpng questions.dot > questions.png
dot\dot.exe -Tplain questions.dot > questions.txt
questions\bin\Debug\questions.exe questions.txt questions.clp
copy questions.clp ..\gardener\res\gardener
