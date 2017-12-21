#!/usr/bin/env python
#--coding:utf-8--
from http.server import BaseHTTPRequestHandler, HTTPServer
from os import path
from urllib.parse import urlparse









import MySQLdb
import time

g_server_list = {
    '斗罗-安卓1服':'111.231.86.238',
    '斗罗-安卓2服':'111.231.54.113',
    '斗罗-安卓3服':'111.231.62.240',
    '斗罗-安卓4服':'122.152.204.111',
    '斗罗-工会1服':'111.231.91.142',
    '斗罗-应用宝1服':'111.231.91.194',
    }


#g_server_list = {
#    '斗罗-安卓1服':'10.154.151.226',
#    '斗罗-安卓2服':'10.105.85.208',
#    '斗罗-安卓3服':'10.105.224.166',
#    '斗罗-安卓4服':'10.105.0.212',
#    '斗罗-工会1服':'10.154.10.131',
#    '斗罗-应用宝1服':'10.154.134.161',
#    }

def db_get_player_num(dbaddr):
    conn = MySQLdb.connect(host=dbaddr,port=3306,user='rydbadmin',passwd='q3NF6hMx5jV0',db='projectdl',charset='utf8')
    cursor = conn.cursor()

    cursor.execute("select count(*) from player;")

    rs = cursor.fetchone()

    cursor.close()
    conn.close()
    return int(rs[0])



def db_get_charge_money(dbaddr):
    conn = MySQLdb.connect(host=dbaddr,port=3306,user='rydbadmin',passwd='q3NF6hMx5jV0',db='projectdl',charset='utf8')
    cursor = conn.cursor()

    cursor.execute("SELECT SUM(param2) as 'aaa' FROM participationlog WHERE TYPE = 54 and Param3 != 2 ;")

    
    rs = cursor.fetchone()
    
    
    cursor.close()
    conn.close()
    if rs[0] != None:
        return int(rs[0])
    else:
        return 0



def db_get_cs_money(dbaddr):
    conn = MySQLdb.connect(host=dbaddr,port=3306,user='rydbadmin',passwd='q3NF6hMx5jV0',db='projectdl',charset='utf8')
    cursor = conn.cursor()

    cursor.execute("SELECT SUM(param2) as 'aaa' FROM participationlog WHERE TYPE = 54 and Param3 = 2 ;")

    
    rs = cursor.fetchone()
    
    
    cursor.close()
    conn.close()
    if rs[0] != None:
        return int(rs[0])
    else:
        return 0



def get_info():
    strdict = '''<table border="1">
    <tr>
        <th>服务器</th>
        <th>注册人数</th>
        <th>充值金额</th>
        <th>客服充值</th>
    </tr>'''
    
    allpeople,allmoney,cs_money_sum = 0,0,0
    for name,addr in g_server_list.items():
        num = db_get_player_num(addr)
        money = db_get_charge_money(addr)
        cs_money = db_get_cs_money(addr)

        strdict += '''<tr>
        <td>%s</td>
        <td>%s</td>
        <td>%d</td>
        <td>%d</td>
        </tr>''' % (name, num, money / 100, cs_money / 100)


        #dict.update({name + '注册人数': num, '充值金额' : money / 100})
        #print(name ,'playernums:', num,'money:',money/100)
        allpeople += num
        allmoney += money / 100
        cs_money_sum += cs_money / 100

    strdict += '''<tr>
    <td>%s</td>
    <td>%s</td>
    <td>%d</td>
    <td>%d</td>
    </tr>''' % ('总计', allpeople, allmoney, cs_money_sum)
    #dict.update({'注册总数': allpeople, '充值总额' : allmoney})

    strdict += '''</table>'''
    return strdict
    #print('allpeople:',allpeople,'allmoney:',allmoney)
    #print('\n')
    #time.sleep(5)





curdir = path.dirname(path.realpath(__file__))
sep = '/'

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

class testHTTPServer_RequestHandler(BaseHTTPRequestHandler):
    # GET
    def do_GET(self):
        sendReply = False
        querypath = urlparse(self.path)
        filepath, query = querypath.path, querypath.query
        
        if filepath.endswith('/'):
            filepath += 'index.html'
        if filepath.endswith('/show'):
            try:
                content = bytes(get_info() + '''
<script language="JavaScript">
function myrefresh()
{
window.location.reload();
}
setTimeout('myrefresh()',10000);
</script>''', encoding = "gbk")

                self.send_response(200)
                self.send_header('Content-type','text/html')
                self.end_headers()
                self.wfile.write(content)
            except IOError:
                self.send_error(404,'File Not Found: %s' % self.path)
            return

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
    port = 8000
    print('starting server, port', port)

    # Server settings
    server_address = ('0.0.0.0', port)
    httpd = HTTPServer(server_address, testHTTPServer_RequestHandler)
    print('running server...')
    httpd.serve_forever()

if __name__ == '__main__':
    run()
