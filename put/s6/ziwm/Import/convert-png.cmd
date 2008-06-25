if exist %1.png if not exist %1.v vips im_png2vips %1.png %1.v
if exist %1.v if not exist %1.ptiff vips im_vips2tiff %1.v %1.ptiff:lzw,tile:256x256,pyramid