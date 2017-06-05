# Opencv : window based stereo matching
- There is an difference between picture looked by left and right camera.  
- Calculate disparity from depth of two images (Left side and Right side).
- So comparison of pixel value between left and right side image is needed.
- For accuray, compare with block size for one pixel (I used 5x5 size).
- Map these all disparity values to new matrix.
- Then can know the picture's depth.
