#!/usr/bin/pyhton
import sys
import re
from PIL import Image, ImageDraw
def search_in_file(file_name, string):
    path = []
    with open(file_name, 'r') as map:
        for line in map:
            if string in line:
                path.append(line.rstrip())
    map.close()
    return path

img = Image.new('RGB', (10000,10000), (128, 128, 128))
draw = ImageDraw.Draw(img)
draw.rectangle((4750, 100, 5250, 600), fill=(0, 255, 0), outline=(0, 0, 0))
draw.rectangle((4750, 9900, 5250, 9400), fill=(0, 255, 0), outline=(0, 0, 0))
x = 0
xy = 0
path1 = search_in_file(sys.argv[1], "L1-")
count_p = path1[0].count("-")
add = 9000 / count_p
while x < count_p:
    x = x + 1
    xy = xy + add
    draw.line(((5000, 500), (xy, 600)), fill=(0, 0, 255), width=3)
    draw.rectangle((xy, 600, (xy - 300), 900), fill=(255, 0, 0), outline=(0, 0, 0), width=5)
    string = 'L'+ str(x) + '-'
    path1 = search_in_file(sys.argv[1], string)
    print('path', x, 'size is :', len(path1) - 1)
    path_size = len(path1) - 2
    add2 = 8000 / path_size
    xy2 = 900
    xy3 = xy
    xy4 = 900
    while path_size > 0:
        path_size = path_size - 1
        xy2 = xy2 + add2
        draw.line((((xy3 - 150), xy4), ((xy3 - 150), (xy2))), fill=(0, 0, 255), width=5)
        draw.rectangle((xy3, xy2, (xy3 - 300), (xy2 + 200)), fill=(255, 0, 0), outline=(0, 0, 0), width=5)
        xy4 = xy2 + 200
    draw.line((((xy3 - 150), (xy2 + 200)), (5000, 9400)), fill=(0, 0, 255), width=5)

img.save('./map.jpg', quality=95)