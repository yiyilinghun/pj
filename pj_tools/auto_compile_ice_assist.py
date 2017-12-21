import sys
import os

# 去除接口定义中多余空格
def replace_all_mulspace(text):
    while text.find('  ') >= 0:
        text = text.replace('  ', ' ')
    return text
##################################################################


# 擦出所有空白
def erase_all_blank(text):
    while text.find(' ') >= 0:
        text = text.replace(' ', '')

    while text.find('\n') >= 0:
        text = text.replace('\n', '')

    while text.find('\t') >= 0:
        text = text.replace('\t', '')
    return text
##################################################################


# 获取接口名称
def get_tar_name(text, interface_tar):
    return text[text.find(interface_tar) + len(interface_tar):-1]
##################################################################


# 解析参数列表
def analysis_params(text):
    fun_name = erase_all_blank(text.split('(')[0])
    text = text[len(text.split('(')[0]):-1]

    text = text.replace('(', '')
    text = text.replace(')', '')
    params = []
    param_in_list = []
    param_out_list = []
    if text.find(',') >= 0:
        params = text.split(',')
    else:
        params.append(text)

    for p in params:
        if len(erase_all_blank(p)) > 3 and erase_all_blank(p)[0:3] == 'out':
            param_out_list.append(p)
        else:
            param_in_list.append(p)

    return fun_name,param_in_list,param_out_list
##################################################################



# 去除传入参数变量名
def erase_in_params_name(text):
    text = text.lstrip(' ')
    text = text.rstrip(' ')
    return text.split(' ')[0]

# 去除传出参数变量名
def erase_out_params_name(text):
    text = text.lstrip(' ')
    text = text.rstrip(' ')
    return text.split(' ')[1]
##################################################################

# 处理传出参数变量名
def handle_param(p,module_name):
    if p == 'bool':
        return 'bool'
    elif p == 'byte':
        return 'qint8'
    elif p == 'short':
        return 'qint16'
    elif p == 'int':
        return 'qint32'
    elif p == 'long':
        return 'qint64'
    elif p == 'float':
        return 'Single'
    elif p == 'double':
        return 'Double'
    elif p == 'string':
        return 'std::string'
    else:
        return '%s::%s' % (module_name, p)
##################################################################

##################################################################
##################################################################
##################################################################
##################################################################
module_tar = 'module '
interface_tar = 'interface '
state_flag = '正在查找模块标记'
module_name = ''
interface_name = ''
interface_info = ''
##################################################################
##################################################################
##################################################################
##################################################################
##################################################################
##################################################################
##################################################################
##################################################################
##################################################################
if len(sys.argv) != 3:
    print('参数个数不符')
    quit()


#work_dir = r'A:\git\pj_pro\pj_common\\'[0:-1]
#src_slice_file = r'pj_Login.ice'
work_dir = sys.argv[1]
src_slice_file = sys.argv[2]

file = open(work_dir + src_slice_file, 'r+')

for line in file:
    if erase_all_blank(line)[0:2] == '//':
        continue
    elif state_flag == '正在查找模块标记':
        if line.find(module_tar) >= 0:
            temp_line = replace_all_mulspace(line)
            module_name = get_tar_name(temp_line, module_tar)
            print('查找到模块', module_name)
            state_flag = '正在查找接口标记'
    elif state_flag == '正在查找接口标记':
        if line.find(interface_tar) >= 0:
            temp_line = replace_all_mulspace(line)
            interface_name = get_tar_name(temp_line, interface_tar)
            interface_info = ''
            print('查找到接口', interface_name)
            state_flag = '检查左花括号'
    elif state_flag == '检查左花括号':
            if erase_all_blank(line) == '{':
                state_flag = '查找接口函数'
            else:
                print('解析失败')
                quit()
    elif state_flag == '查找接口函数':
            if erase_all_blank(line) == '};':
                state_flag = '查找接口函数结束'
                if interface_info != '':
                    interface_info = ''
                state_flag = '正在查找接口标记'
            else:
                temp_line = replace_all_mulspace(line)

                fun_name, _param_in_list, _param_out_list = analysis_params(temp_line[5:-1])
                diy_head = 'ICE_CALL%d_RET%d' % (len(_param_in_list), len(_param_out_list))

                param_in_list = []
                param_out_list = []

                for x in _param_in_list:
                    param_in_list.append(erase_in_params_name(x))
                for x in _param_out_list:
                    param_out_list.append(erase_out_params_name(x))

                in_ps = ''
                for p in param_in_list:
                    in_ps += handle_param(p, module_name) + ','
                in_ps = in_ps.rstrip(',')

                out_ps = ''
                for p in param_out_list:
                    out_ps += handle_param(p, module_name) + ','
                out_ps = out_ps.rstrip(',')

                if len(in_ps) > 0 and len(out_ps) > 0:
                    print('%s(%s,%s,%s);' % (diy_head, fun_name, in_ps, out_ps))
                    interface_info += '%s(%s,%s,%s);\n' % (diy_head, fun_name, in_ps, out_ps)
                elif len(in_ps) > 0 and len(out_ps) == 0:
                    print('%s(%s,%s);' % (diy_head, fun_name, in_ps))
                    interface_info += '%s(%s,%s);\n' % (diy_head, fun_name, in_ps)
                elif len(in_ps) == 0 and len(out_ps) > 0:
                    print('%s(%s,%s);' % (diy_head, fun_name, out_ps))
                    interface_info += '%s(%s,%s);\n' % (diy_head, fun_name, out_ps)
                elif len(in_ps) == 0 and len(out_ps) == 0:
                    print('%s(%s);' % (diy_head, fun_name))
                    interface_info += '%s(%s);\n' % (diy_head, fun_name)

                ms_interface_file = open(work_dir + 'Ms' + interface_name + '.h', 'w+')
                ms_interface_file.writelines(
'''#include "macro.h"
#include "%s"
#include "ice_call_assist.h"
class %s
    : public ice_call_assist<MsNet::%sPrx>
{
#pragma region BASE_AND_SLOTS
    Q_OBJECT;
    public Q_SLOTS:
public:
    void begin(int32_t msec = 1)
    {
        m_QTimer.setInterval(msec);
        QObject::connect(&m_QTimer, &QTimer::timeout, this, &%s::ice_call_tick);
        m_QTimer.start();
    }
    void ice_call_tick() { return this->_ice_call_tick(); }
#pragma endregion
public:
%s
};
''' % (src_slice_file[0:src_slice_file.find('.') + 1] + 'h',
       'Ms' + interface_name,
       interface_name,
       'Ms' + interface_name,
       interface_info)
)

                #print('fun:', fun_name, temp_line, sep='')
                #print(replace_all_mulspace(line))

        #print(temp_line)

        #print('aaa bbb'[:'aaa bbb'.find('aaa')])
        #print(line)
#os.system('pause')

