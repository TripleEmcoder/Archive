if exist %1.bin.gz if not exist %1.bin gzip -d -k %1.bin.gz
if exist %1.bin if not exist %1.tiff raw2tiff -w 86400 -l 43200 -b 3 -d byte -p rgb -c zip %1.bin %1.tiff
if exist %1.tiff if not exist %1.v vips im_tiff2vips %1.tiff %1.v
if exist %1.v if not exist %1.ptiff vips im_vips2tiff %1.v %1.ptiff:deflate,tile:256x256,pyramid