#!/usr/bin/env python
#--coding:utf-8--
# import ptvsd
import threading
from multiprocessing.dummy import Pool as ThreadPool
from http.server import BaseHTTPRequestHandler, HTTPServer
from os import path
from urllib.parse import urlparse
import MySQLdb
import time
import os
import sys

if len(sys.argv) != 3:
    print('参数个数不符')
    quit()

if sys.argv[1] == 'out':
    use_outside_addr = True
elif sys.argv[1] == 'in':
    use_outside_addr = False
else:
    quit()

try:
    int(sys.argv[2])
except :
    quit()

g_server_outside_addr_list = {
    '****混服':{
        '****-混服1服':'111.231.86.238',
        '****-混服2服':'111.231.54.113',
        '****-混服3服':'111.231.62.240',
        '****-混服4服':'122.152.204.111',
        '****-混服5服':'111.231.107.13',
        '****-混服6服':'111.231.87.237',
        '****-混服7服':'111.231.104.28',
        '****-混服8服':'111.231.85.61',
        '****-混服9服':'122.152.192.228',
        '****-混服10服':'111.231.135.225',
        '****-混服11服':'111.231.54.33',
        '****-混服12服':'111.231.99.28',
        '****-混服13服':'122.152.209.167',
        '****-混服14服':'111.231.93.135',
        '****-混服15服':'111.231.90.141',
        '****-混服16服':'111.231.66.25',
        '****-混服17服':'111.231.76.75',
        '****-混服18服':'111.231.75.181',
        '****-混服19服':'111.231.94.188',
        '****-混服20服':'111.231.94.223',
        '****-混服21服':'111.231.91.40',
    },
    
    '****工会':{
        '****-工会1服':'111.231.91.142',
        '****-工会2服':'122.152.217.185',
        '****-工会3服':'111.231.89.88',
        '****-工会4服':'111.231.88.75',
        '****-工会5服':'111.231.112.13',
        '****-工会6服':'111.231.86.159',
        '****-工会7服':'111.231.105.206',
        '****-工会8服':'122.152.212.43',
        '****-工会9服':'211.159.216.48',
        '****-工会10服':'111.231.63.144',
    },
    
    '****应用宝':{
        '****-应用宝1服':'111.231.91.194',
        '****-应用宝2服':'111.231.89.41',
        '****-应用宝3服':'111.231.88.82',
        '****-应用宝4服':'111.231.89.118',
        '****-应用宝5服':'111.231.89.45',
        '****-应用宝6服':'111.231.90.171',
        '****-应用宝7服':'111.231.50.85',
        '****-应用宝8服':'111.231.87.23',
        '****-应用宝9服':'111.231.142.248',
        '****-应用宝10服':'122.152.210.139',
    },
}

g_server_inside_addr_list = {
    '****混服':{
        '****-混服1服':'10.154.151.226',
        '****-混服2服':'10.105.85.208',
        '****-混服3服':'10.105.224.166',
        '****-混服4服':'10.105.0.212',
        '****-混服5服':'10.105.122.219',
        '****-混服6服':'10.105.115.188',
        '****-混服7服':'10.105.2.198',
        '****-混服8服':'10.105.13.185',
        '****-混服9服':'10.105.120.23',
        '****-混服10服':'10.105.11.213',
        '****-混服11服':'10.105.23.174',
        '****-混服12服':'10.105.41.250',
        '****-混服13服':'10.105.102.231',
        '****-混服14服':'10.105.64.184',
        '****-混服15服':'10.105.251.226',
        '****-混服16服':'10.105.56.210',
        '****-混服17服':'10.105.99.252',
        '****-混服18服':'10.105.111.34',
        '****-混服19服':'10.105.203.73',
        '****-混服20服':'10.105.104.92',
        '****-混服21服':'10.105.16.161',
    },

    '****工会':{
        '****-工会1服':'10.154.10.131',
        '****-工会2服':'10.133.192.157',
        '****-工会3服':'10.105.213.47',
        '****-工会4服':'10.105.193.118',
        '****-工会5服':'10.105.221.111',
        '****-工会6服':'10.105.18.48',
        '****-工会7服':'10.105.206.235',
        '****-工会8服':'10.105.31.160',
        '****-工会9服':'10.105.29.210',
        '****-工会10服':'10.105.193.178',
    },

    '****应用宝':{
        '****-应用宝1服':'10.154.134.161',
        '****-应用宝2服':'10.105.116.149',
        '****-应用宝3服':'10.105.73.43',
        '****-应用宝4服':'10.105.122.78',
        '****-应用宝5服':'10.105.16.108',
        '****-应用宝6服':'10.105.89.74',
        '****-应用宝7服':'10.105.243.29',
        '****-应用宝8服':'10.105.127.179',
        '****-应用宝9服':'10.105.210.66',
        '****-应用宝10服':'10.105.223.248',
    },}

const_html_js_reload_str = '''<script language="JavaScript">
function myrefresh(){window.location.reload();}
setTimeout('myrefresh()',5000);</script>
<style>
td {
white-space: nowrap;
font-size :1.8rem;
}
th{
    font-size :1.8rem;
}
</style>'''

# MIME-TYPE
mimedic = [('.py', 'zip/py'),
    ('.html', 'text/html'),
    ('.htm', 'text/html'),
    ('.js', 'application/javascript'),
    ('.css', 'text/css'),
    ('.json', 'application/json'),
    ('.png', 'image/png'),
    ('.jpg', 'image/jpeg'),
    ('.gif', 'image/gif'),
    ('.txt', 'text/plain'),
    ('.avi', 'video/x-msvideo'),]

# 统计信息
def db_get_num_info(name, dbaddr):
    try:
        conn = MySQLdb.connect(host=dbaddr,port=3306,user='read',passwd='Haymaker@88',db='projectdl',charset='utf8')
        cursor = conn.cursor()

        #cursor.execute("select count(*) from player;")
        cursor.execute("select count(distinct DeviceID) from account ;")
        rs_device_sum = cursor.fetchone()
        rs_device_sum = (rs_device_sum[0] is not None and int(rs_device_sum[0])) or 0

        cursor.execute("SELECT SUM(param2) FROM participationlog WHERE TYPE = 54 and Param3 != 2 ;")
        rs_money_sum = cursor.fetchone()
        rs_money_sum = (rs_money_sum[0] is not None and int(rs_money_sum[0])) or 0

        cursor.execute("SELECT SUM(param2) FROM participationlog WHERE TYPE = 54 and Param3 = 2 ;")
        rs_cs_money_sum = cursor.fetchone()
        rs_cs_money_sum = (rs_cs_money_sum[0] is not None and int(rs_cs_money_sum[0])) or 0

        cursor.execute("SELECT count(*) FROM player WHERE MobilePhoneBindInfo_PhoneNumber != '';")
        rs_has_phone_sum = cursor.fetchone()
        rs_has_phone_sum = (rs_has_phone_sum[0] is not None and int(rs_has_phone_sum[0])) or 0

        cursor.close()
        conn.close()

        plyaer_sum = db_get_online_info(dbaddr)
    except :
        rs_device_sum = 0
        rs_money_sum = 0 
        rs_cs_money_sum = 0
        plyaer_sum = 0
        rs_has_phone_sum = 0
        name = name
    finally:
        return rs_device_sum, rs_money_sum, rs_cs_money_sum, plyaer_sum, rs_has_phone_sum, name


##################################################################
def db_get_online_info(dbaddr):
    conn = MySQLdb.connect(host=dbaddr,port=3306,user='read',passwd='Haymaker@88',db='count',charset='utf8')
    cursor = conn.cursor()

    #cursor.execute("select count(*) from player;")
    cursor.execute("select number from online where port = 52113 ;")
    rs_online_in_cell_sum = cursor.fetchone()
    rs_online_in_cell_sum = (rs_online_in_cell_sum[0] is not None and int(rs_online_in_cell_sum[0])) or 0

    cursor.close()
    conn.close()
    return rs_online_in_cell_sum


##################################################################
def _parallel_get_channel_info(*servers):
    subtotal_strdict = ''
    strdict = '''<table border="1" align="center" border="8" width="1000">
    <tr>
        <th>%s</th>
        <th>设备数量</th>
        <th>在线数量</th>
        <th>充值金额</th>
        <th>ARPU</th>
        <th>客服充值</th>
        <th>手机绑定</th>
    </tr><br/>''' % (servers[0])
    
    subtotal_devicesum = 0
    subtotal_online_cell_sum = 0
    subtotal_moneysum = 0
    subtotal_csmoneysum = 0
    subtotal_phone_sum = 0
    result = []
    tPool = ThreadPool(100)
    for name,addr in servers[1].items():
        result.append(tPool.apply_async(db_get_num_info, [name, addr]))

    tPool.close()
    tPool.join()
    for res in result:
        num, money, cs_money, online_in_cell_sum, rs_has_phone_sum, name = res.get()
        if num == 0:
            num = '查询失败'
        strdict += '''<tr align="center" border="8" width="1000">
        <td>%s</td>
        <td>%s</td>
        <td>%d</td>
        <td>%d</td>
        <td>%0.2f</td>
        <td>%d</td>
        <td>%d</td>
        </tr>''' % (name, num, online_in_cell_sum, money / 100, float(money / 100) / float(num), cs_money / 100, rs_has_phone_sum)
        subtotal_devicesum += num
        subtotal_online_cell_sum += online_in_cell_sum
        subtotal_moneysum += money / 100
        subtotal_csmoneysum += cs_money / 100
        subtotal_phone_sum += rs_has_phone_sum

    if subtotal_devicesum == 0:
        subtotal_devicesum = -1
    subtotal_strdict += '''<tr align="center" border="8" width="1000">
    <td>%s</td>
    <td>%s</td>
    <td>%d</td>
    <td>%d</td>
    <td>%0.2f</td>
    <td>%d</td>
    <td>%d</td>
    </tr>''' % (servers[0], subtotal_devicesum, subtotal_online_cell_sum, subtotal_moneysum, float(subtotal_moneysum) / float(subtotal_devicesum), subtotal_csmoneysum, subtotal_phone_sum)

    strdict += '''</table>'''

    return strdict, subtotal_strdict, subtotal_devicesum, subtotal_online_cell_sum, subtotal_moneysum, subtotal_csmoneysum, subtotal_phone_sum
##################################################################
def get_info():
    total_devicesum = 0
    total_online_cell_sum = 0
    total_moneysum = 0
    total_csmoneysum = 0
    total_phone_sum = 0

    subtotal_strdict = '''<table border="1" align="center" border="8" width="1000">
        <tr>
            <th>渠道小计</th>
            <th>设备数量</th>
            <th>在线数量</th>
            <th>充值金额</th>
            <th>ARPU</th>
            <th>客服充值</th>
            <th>手机绑定</th>
        </tr><br/>
    '''
    server_list = None
    if use_outside_addr:
        server_list = g_server_outside_addr_list
    else:
        server_list = g_server_inside_addr_list
    strlist = []


    result = []
    tPool = ThreadPool(10)
    for servers in server_list.items():
        result.append(tPool.apply_async(_parallel_get_channel_info, servers))
    tPool.close()
    tPool.join()

    for res in result:
        strdict, _subtotal_strdict, subtotal_devicesum, subtotal_online_cell_sum, subtotal_moneysum, subtotal_csmoneysum, subtotal_phone_sum = res.get()
        strlist.append(strdict)
        total_devicesum += subtotal_devicesum
        total_online_cell_sum += subtotal_online_cell_sum
        total_moneysum += subtotal_moneysum
        total_csmoneysum += subtotal_csmoneysum
        total_phone_sum += subtotal_phone_sum
        subtotal_strdict += _subtotal_strdict


    if total_devicesum == 0:
        total_devicesum = -1
    subtotal_strdict += '''<tr align="center" border="8" width="1000">
    <td>%s</td>
    <td>%s</td>
    <td>%d</td>
    <td>%d</td>
    <td>%0.2f</td>
    <td>%d</td>
    <td>%d</td>
    </tr>''' % ('总计', total_devicesum, total_online_cell_sum, total_moneysum, float(total_moneysum) / float(total_devicesum), total_csmoneysum, total_phone_sum)
    return strlist, subtotal_strdict

g_bytes_hunfu_info = None
g_bytes_gonghui_info = None
g_bytes_yyb_info = None
g_bytesinfo = None
def thread_tar():
    #for x in range(2):
    while True:
        try:
            print('开始拉取')
            global g_bytesinfo
            server_info, total_info = get_info()
            temp = ''
            for x in server_info:
                temp += x
            g_bytesinfo = bytes(total_info + temp + const_html_js_reload_str, encoding = "gbk")
        finally:
            print('拉取完毕')
            time.sleep(5)

# main
t = threading.Thread(target=thread_tar)
t.start()

curdir = path.dirname(path.realpath(__file__))
sep = '/'

class testHTTPServer_RequestHandler(BaseHTTPRequestHandler):
    # GET
    def do_GET(self):
        sendReply = False
        querypath = urlparse(self.path)
        filepath, query = querypath.path, querypath.query
        
        if filepath.endswith('/') or filepath.endswith('/show'):
            try:
                global g_bytesinfo
                if g_bytesinfo is None:
                    content = bytes('''<table border="1" align="center" border="8" width="1000">
                    <tr><th>新服开启,页面初始化中...</th></tr><br/>''' + const_html_js_reload_str, encoding = "gbk")
                else:
                    content = g_bytesinfo
                self.send_response(200)
                self.send_header('Content-type','text/html')
                self.end_headers()
                self.wfile.write(content)
            except IOError:
                self.send_error(404,'File Not Found: %s' % self.path)

        filename, fileext = path.splitext(filepath)
        for e in mimedic:
            if e[0] == fileext:
                mimetype = e[1]
                sendReply = True

        if sendReply == True:
            try:
                with open(path.realpath(curdir + sep + filepath),'rb') as f:
                    content = f.read()
                    self.send_response(200)
                    self.send_header('Content-type',mimetype)
                    self.end_headers()
                    self.wfile.write(content)
            except IOError:
                self.send_error(404,'File Not Found: %s' % self.path)

def run():
    port = int(sys.argv[2])
    print('starting server, port', port)

    # Server settings
    server_address = ('0.0.0.0', port)
    httpd = HTTPServer(server_address, testHTTPServer_RequestHandler)
    print('running server...')
    httpd.serve_forever()

if __name__ == '__main__':
    run()

