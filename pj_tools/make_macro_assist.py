import sys
import os

############################################################
def make_pt_list(pc, rc):
    ret = ''
    i = 0
    while i < pc:
        i += 1
        ret += r',pt%d' % i
    return ret
############################################################
def make_rt_list(pc, rc):
    ret = ''
    i = 0
    while i < rc:
        i += 1
        ret += r',rt%d' % i
    return ret
############################################################
def make_pt_rt_list(pc, rc):
    ret = ''
    i = 0
    while i < pc:
        i += 1
        ret += r', pt%d' % i
    i = 0
    while i < rc:
        i += 1
        ret += r', rt%d' % i
    return ret
############################################################
def make_pt_const_list(pc, rc):
    ret = ''
    i = 0
    while i < pc:
        i+=1
        ret += r'const pt%d&, ' % i
    return ret
############################################################
def make_p_typedef_list(pc, rc):
    ret = ''
    i = 0
    while i < pc:
        i += 1
        ret += '\ntypedef pt1 rpc_call##p%d;\\' % i
    return ret
############################################################
def make_r_typedef_list(pc, rc):
    ret = ''
    i = 0
    while i < rc:
        i += 1
        ret += '\ntypedef rt1 rpc_call##r%d;\\' % i
    return ret
############################################################
def make_pt_const_list(pc, rc):
    ret = ''
    i = 0
    while i < pc:
        i += 1
        ret += ', const pt%d&' % i
    return ret
############################################################
def make_fpt_const_list(pc, rc):
    ret = ''
    i = 0
    while i < pc:
        i += 1
        ret += 'const pt%d&, ' % i
    return ret
############################################################
def make_rt_const_list(pc, rc):
    ret = ''
    i = 0
    while i < rc:
        i += 1
        ret += ', const rt%d&' % i

    return ret
############################################################
def make_pt_const_p_list(pc, rc):
    ret = ''
    i = 0
    while i < pc:
        i += 1
        ret += 'const pt%d p%d, ' % (i, i)
    return ret
############################################################
def make_pt_const_p_list_at_end(pc, rc):
    ret = ''
    i = 0
    while i < pc:
        i += 1
        ret += 'const pt%d p%d, ' % (i, i)
    if i > 0:
        ret = ret[:-2]
    return ret
############################################################
def make_p_list(pc, rc):
    ret = ''
    i = 0
    while i < pc:
        i += 1
        ret += r'p%d, ' % i
    if i > 0:
        ret = ret[:-2]
    return ret
############################################################
def make_r_list(pc, rc):
    ret = ''
    i = 0
    while i < rc:
        i += 1
        ret += r'r%d, ' % i
    return ret
############################################################
def make_pr_list(pc, rc):
    ret = ''
    i = 0
    while i < pc:
        i += 1
        ret += r', p%d' % i
    i = 0
    while i < rc:
        i += 1
        ret += r', r%d' % i
    return ret
############################################################
def make_r_list2(pc, rc):
    ret = ''
    i = 0
    while i < rc:
        i += 1
        ret += r' ,r%d' % i
    return ret
############################################################
def make_rt_r_lines(pc, rc):
    ret = ''
    i = 0
    while i < rc:
        i += 1
        ret += '\nrt%d r%d;\\' % (i, i)
    return ret
############################################################
def make_p_decltype_lines(pc, rc):
    ret = ''
    i = 0
    while i < pc:
        i += 1
        ret += '\n,const decltype(_prx)::rpc_call##p%d& p%d \\' % (i, i)
    return ret
############################################################
def make_r_decltype_lines(pc, rc):
    ret = ''
    i = 0
    while i < rc:
        i += 1
        ret += '\n,const decltype(_prx)::rpc_call##r%d& r%d \\' % (i, i)
    return ret
############################################################
def write_macro(file, pc, rc):
    file.write(r'''
#pragma region ICE_PRC远程调用%(p_count)d参,%(r_count)d返
#define ICE_CALL%(p_count)d_RET%(r_count)d(rpc_call%(pt_rt_list)s) \
bool rpc_call(%(fpt_const_list)s const ::Ice::Context& context = Ice::noExplicitContext);\%(p_typedef_list)s%(r_typedef_list)s
bool ice_default_cb##rpc_call(bool%(pt_const_list)s %(rt_const_list)s);\
void ms##rpc_call(%(pt_const_p_list_at_end)s)\
{\
m_setAsyncResult.insert(m_Prx->begin_##rpc_call(%(p_list)s), \
[=](const ::Ice::AsyncResultPtr& xAsynResult){\%(rt_r_lines)s
bool _ice_result = m_Prx->end_##rpc_call(%(r_list)sxAsynResult);\
return ice_default_cb##rpc_call(_ice_result%(pr_list)s);});\
}\
void ms##rpc_call(%(pt_const_p_list)s std::function<bool(bool%(pt_const_list)s %(rt_const_list)s)> lambdac_all)\
{\
m_setAsyncResult.insert(m_Prx->begin_##rpc_call(%(p_list)s), \
[=](const ::Ice::AsyncResultPtr& xAsynResult){\%(rt_r_lines)s
bool _ice_result = m_Prx->end_##rpc_call(%(r_list)sxAsynResult);\
return lambdac_all(_ice_result %(pr_list)s);});\
}
#define ICE_DIY_CALL%(p_count)d_RET%(r_count)d(_prx, rpc_call, _p1) _prx.ms##rpc_call(_p1, [=](bool ice_ret \%(p_decltype_lines)s%(r_decltype_lines)s
)
#pragma endregion
''' % {'p_count' : pc,
       'r_count' : rc,
       'p_list' : make_p_list(pc, rc),
       'r_list' : make_r_list(pc, rc),
       'pr_list' : make_pr_list(pc, rc),
       'pt_list' : make_pt_list(pc, rc),
       'rt_list' : make_rt_list(pc, rc),
       'pt_rt_list' : make_pt_rt_list(pc, rc),
       'pt_const_list' : make_pt_const_list(pc, rc),
       'fpt_const_list' : make_fpt_const_list(pc, rc),
       'p_typedef_list' : make_p_typedef_list(pc, rc),
       'r_typedef_list' : make_r_typedef_list(pc, rc),
       'rt_const_list' : make_rt_const_list(pc, rc),
       'pt_const_p_list' : make_pt_const_p_list(pc, rc),
       'pt_const_p_list_at_end' : make_pt_const_p_list_at_end(pc, rc),
       'r_list2' : make_r_list2(pc, rc),
       'rt_r_lines' : make_rt_r_lines(pc, rc),
       'p_decltype_lines' : make_p_decltype_lines(pc, rc),
       'r_decltype_lines' : make_r_decltype_lines(pc, rc),
       })
############################################################
file = open('A:\git\pj_pro\pj_common\macro.h', 'w+')

for i in range(9):
    for j in range(9):
        write_macro(file, i, j)
