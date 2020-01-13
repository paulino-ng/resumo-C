@echo off

rem isto e um comentario

where pandoc
IF ERRORLEVEL 1 CALL %USERPROFILE%\noserver.bat

FOR %%f IN (L*.md) DO pandoc -f markdown -s -t html -o %%~nf.html %%~nf.md
