# -*- coding: utf-8 -*-
import tab_VoltageTowerLevelAttr_pb2
import codecs

def addItem(item, args):
	item.id = int(args[0])
	item.Comment = args[1]
	item.Level = int(args[2])
	item.ShootDist = int(args[3])
	

table = tab_VoltageTowerLevelAttr_pb2.tab_VoltageTowerLevelAttrTable()
table.tname = 'tab_VoltageTowerLevelAttr.dbp'
rf = codecs.open('/Users/woodcol/Documents/cocos2dx/demo-datebase/txt_protobuf/tab_VoltageTowerLevelAttr.txt', encoding='utf-8')
rf.readline()
rf.readline()
rf.readline()
while True:
    line = rf.readline()
    if (len(line) == 0):break
    arr = line.replace('\r', '\n').split('\n')[0].split('\t')
    addItem(table.tlist.add(), arr)

f = file('/Users/woodcol/Documents/cocos2dx/demo-datebase/dbp/tab_VoltageTowerLevelAttr.dbp', 'wb')
f.write(table.SerializeToString())
f.close()
