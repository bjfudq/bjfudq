# coding=utf-8
# ds 上传辅助工具 选择章以及语言，新建一个对应该章该语言的文件夹，方便上传
import sys
import os

if __name__ == "__main__":
    if len(sys.argv) < 3 or sys.argv[2] not in ['c', 'c++', 'cpp']:
        print '[USAGE] python build_chapter.py chapter_dir lang_config[c/c++/cpp]'
        print '[USAGE] eg. '
        print '[USAGE] python build_chapter.py chapter1 c++'
        sys.exit(254)
    rootdir = sys.argv[1]
    lang = sys.argv[2]

    if lang == 'c++':
        lang = 'cpp'


    if rootdir[-1] == '/':
        rootdir = rootdir[:-1]

    lst = {}
    cnt = 0
    for parent, dirnames, filenames in os.walk(rootdir):
        for filename in filenames:
            if parent == rootdir:
                if len(filename.split("_")) <= 1:
                    continue
                i = filename.split('_')[0]
                lst[i] = '_'.join(filename.split("_")[1:])
                try:
                    num = int(i)
                except:
                    if i[-1] == 'p':
                        num = int(i[:-3])
                    elif i[-1] == 'c':
                        num = int(i[:-1])
                    else:
                        continue

                if num > cnt:
                    cnt = num


    f = open(rootdir + "/content.md")

    line = f.readline().strip()

    while True:
        line = f.readline().strip()
        if len(line) != 0:
            break;

    line = f.readline().strip()
    newdir = rootdir.split("/")[0] + "_build"
    print "rm -rf " + newdir + " || true"
    os.system("rm -rf " + newdir + " || true")
    print "mkdir " + newdir
    os.system("mkdir " + newdir)
    print "cp " + rootdir + "/content.md " + newdir + "/content.md"
    os.system("cp " + rootdir + "/content.md " + newdir + "/content.md")
    for i in range(1, cnt + 1):
        line = f.readline().strip()
        if '伴随' in line or '跟随' in line:
            oldfile = rootdir + '/' + str(i) + lang + "_" + lst[str(i) + lang]
            newfile = newdir + '/' + str(i) + "_" + lst[str(i) + lang]
            print "cp " + oldfile + " " + newfile
            os.system("cp " + oldfile + " " + newfile)
        else:
            oldfile = rootdir + '/' + str(i) + "_" + lst[str(i)]
            newfile = newdir + '/' + str(i) + "_" + lst[str(i)]
            print "cp " + oldfile + " " + newfile
            os.system("cp " + oldfile + " " + newfile)
