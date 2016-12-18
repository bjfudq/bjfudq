# -*- coding: utf-8 -*-
#处理目标目录下，将文件名中带 cpp 的文件，把 cpp 替换成 c，然后复制成一个新文件

import os
import sys
import shutil

def deal(file_dir):
    for file in os.listdir(file_dir):
        if file.find('cpp') != -1:
            str=file.replace('cpp', 'c')
            print 'newfilename: %s\n' % str
            shutil.copyfile(file_dir+'/'+file,file_dir+'/'+str)

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print '[USAGE] python filescan.py chapter_dir'
        print '[USAGE] eg. '
        print '[USAGE] python filescan.py data_structure_1/chapter1'
        sys.exit(254)
    filename=sys.argv[1]
    deal(filename)
