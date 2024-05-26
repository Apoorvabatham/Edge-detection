from test_case import *


TEST_SUITE = [
    # Ex 1
    ApplyThresholdTestCase('public', 'threshold1', 'threshold1', 1),
    


    # Ex 2
    GradientMagnitudeTestCase('public', 'gm1', 'gm1_dx', 'gm1_dy', 'gm1'),
    


    # Ex 3
    ScaleImageTestCase('public', 'scale_image_1', 'scale_image_1'),
    

    
    # Ex 4
    GetPixelValueTestCase('public', 'small1', [(0, 0, 1), (2, 2, 9)], name='small1-pv1'),


    ConvolveTestCase('public', 'convolve1', 'convolve1', 'kernel1'),


    
    # Ex 5
    ReadBrokenImageTestCase('public', 'imgbroken1'),
    ReadBrokenImageTestCase('public', 'imgbroken2'),
    


    ReadImageTestCase('public', 'small1', 'small1', name='small1-read'),
    


    WriteImageTestCase('public', 'small1', 'small1', 'small1', name='small1-write'),


    
    # Ex 6
    MainTestCase('public', 'img_P', 100),

    # Custom Tests
ApplyThresholdTestCase('custom', 'threshold_equal', 'threshold_equal', 1),
GradientMagnitudeTestCase('custom', 'gradientmagnitude_custom', 'gradientmagnitude_custom_dx', 'gradientmagnitude_custom_dy', 'gm1'),
ScaleImageTestCase('custom', 'scale_uniform', 'scale_uniform'),
ScaleImageTestCase('custom', 'scale_more_complex', 'scale_more_complex'),
ScaleImageTestCase('custom', 'scale_big_numbers', 'scale_big_numbers'),
GetPixelValueTestCase('custom', 'small1', [(3, 0, 3), (4, 0, 2), (5, 0, 1), (-1, 0, 1), (1, -2, 5), (4, 5, 2), (-1, -2, 4), (-3, 1, 6), (5, -3, 7)], name='more-small1-pv'),
ReadBrokenImageTestCase('custom', 'imgbroken_custom_1'),
ReadBrokenImageTestCase('custom', 'imgbroken_custom_2'),
ReadBrokenImageTestCase('custom', 'imgbroken_custom_3'),
ReadBrokenImageTestCase('custom', 'imgbroken_custom_4'),
ReadImageTestCase('custom', 'edgecase_img', 'edgecase_img', name='edgecase_img-read'),
WriteImageTestCase('custom', 'write_one_by_ten', 'write_one_by_ten', 'write_one_by_ten', name='one_by_ten-write'),
    

]
