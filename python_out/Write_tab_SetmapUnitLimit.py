# -*- coding: utf-8 -*-
import tab_SetmapUnitLimit_pb2
import codecs

def addItem(item, args):
	item.id = int(args[0])
	item.Comment = args[1]
	item.Level = int(args[2])
	item.InGameName = int(args[3])
	item.UnitLimits = int(args[4])
	

table = tab_SetmapUnitLimit_pb2.tab_SetmapUnitLimitTable()
table.tname = 'tab_SetmapUnitLimit.dbp'
rf = codecs.open('/Users/woodcol/Documents/cocos2dx/demo-datebase/txt_protobuf/tab_SetmapUnitLimit.txt', encoding='utf-8')
rf.readline()
rf.readline()
rf.readline()
while True:
    line = rf.readline()
    if (len(line) == 0):break
    arr = line.replace('\r', '\n').split('\n')[0].split('\t')
    addItem(table.tlist.add(), arr)

f = file('/Users/woodcol/Documents/cocos2dx/demo-datebase/dbp/tab_SetmapUnitLimit.dbp', 'wb')
f.write(table.SerializeToString())
f.close()
