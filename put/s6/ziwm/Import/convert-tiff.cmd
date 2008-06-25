if exist %1.tiff if not exist %1.v vips im_tiff2vips %1.tiff %1.v
if exist %1.v if not exist %1.ptiff vips im_vips2tiff %1.v %1.ptiff:deflate,tile:256x256,pyramid