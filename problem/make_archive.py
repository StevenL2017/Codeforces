import os
import shutil


if __name__ == '__main__':
    base = 'archive'

    filenames = os.listdir('./')
    for filename in filenames:
        if not filename[0].isdigit(): continue

        folder = ''
        for c in filename:
            if c.isdigit():
                folder += c
            else:
                break

        foldername = os.path.join(base, folder)
        if not os.path.exists(foldername):
            os.makedirs(foldername)
        
        shutil.move(filename, os.path.join(foldername, filename))
