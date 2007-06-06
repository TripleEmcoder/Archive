@echo off
downloader\ITDT.Tools.XmlDownloader.exe downloads\bin\Debug\downloads.dll SuperOgrod.xml
copy SuperOgrod\Encyklopedia.xml plants.xml
copy plants.xml ..\gardener\res\gardener