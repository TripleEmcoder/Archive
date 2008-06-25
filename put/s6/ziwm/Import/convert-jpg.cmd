if exist %1.jpg if not exist %1.v vips im_jpeg2vips %1.jpg %1.v
if exist %1.v if not exist %1.ptiff vips im_vips2tiff %1.v %1.ptiff:deflate,tile:256x256,pyramid