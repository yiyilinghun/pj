import httplib2


while True:
    try:
        h = httplib2.Http()
        resp, content = h.request("http://192.168.4.227:8000/", "GET")
        #resp, content = h.request("http://118.89.157.62:8000/", "GET")
        #print('ok')
        del(h)
    except Exception as e:
        print(e)
        fail+=1
        print('error')
