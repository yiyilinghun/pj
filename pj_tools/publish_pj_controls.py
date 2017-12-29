import sys
from multiprocessing.context import Process
import os
import shutil

def copy_pj_control(file_name):
    shutil.copy(r'A:\git\pj_pro\bin\Release\x64\%s.dll' % file_name, r'A:\Qt5.10.0\5.10.0\msvc2017_64\plugins\designer\\'[:-1])
    print('发布%s成功' % file_name)


#p = Process(target='A:\Qt5.10.0\5.10.0\msvc2017_64\bin\designer.exe')
#p.st
#p.start()

#os.pro
os.system('taskkill /IM designer.exe')
copy_pj_control('pj_button')
copy_pj_control('pj_checkbox')
copy_pj_control('pj_groupbox')
copy_pj_control('pj_label')
copy_pj_control('pj_listview')
copy_pj_control('pj_linebox')
copy_pj_control('pj_textbox')
#copy_pj_control('pj_toolbox')
#copy_pj_control('pj_widget');
os.system(r'start "" A:\Qt5.10.0\5.10.0\msvc2017_64\bin\designer.exe')
#os.system('pause')
