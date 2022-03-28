# 这是之前写的一个小项目，现在直接拿来用
import urllib.request, urllib.error
import time
import socket
import json


def 获取网页(链接, cookie):
    m = -1
    while m == -1:
        消息头 = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.69 Safari/537.36 Edg/95.0.1020.53',
            'Cookie': cookie
        }
        socket.setdefaulttimeout(10.0)
        请求 = urllib.request.Request(链接, headers=消息头, method='GET')
        try:
            返回的内容 = urllib.request.urlopen(请求, timeout=5)
            网页内容 = 返回的内容.read()
            m = 0
        except urllib.error.URLError as 错误:
            if hasattr(错误, "code"):
                print("错误代码：", 错误.code)
            if hasattr(错误, "reason"):
                print("错误原因：\n", 错误.reason)
            urllib.request.urlcleanup()
            m = -1
            time.sleep(3)
    urllib.request.urlcleanup()
    return 网页内容.decode('utf8')


url="https://view.inews.qq.com/g2/getOnsInfo?name=disease_h5" #调用腾讯提供的api
data_json=获取网页(url, '')
data_info = json.loads(json.loads(data_json)['data'])['areaTree'][0]['children'][1]['children'] # 解析api
fd=open("data.d","w")
fn=open("data.n","w")
total_data = ""
for item in data_info:
    fn.write(item['name']+'\n')
    fd.write(str(item['total']['nowConfirm'])+'\n')