if exist %1.jp2 if not exist %1.ppm kdu_expand -i %1.jp2 %1.ppm
if exist %1.ppm if not exist %1.v vips im_ppm2vips %1.ppm %1.v
if exist %1.v if not exist %1.ptiff vips im_vips2tiff %1.v %1.ptiff:deflate,tile:256x256,pyramid