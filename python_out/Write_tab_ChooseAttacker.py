# -*- coding: utf-8 -*-
import tab_ChooseAttacker_pb2
import codecs

def addItem(item, args):
	item.id = int(args[0])
	item.Comment = args[1]
	item.Level = int(args[2])
	item.NeedCoins = int(args[3])
	

table = tab_ChooseAttacker_pb2.tab_ChooseAttackerTable()
table.tname = 'tab_ChooseAttacker.dbp'
rf = codecs.open('/Users/woodcol/Documents/cocos2dx/demo-datebase/txt_protobuf/tab_ChooseAttacker.txt', encoding='utf-8')
rf.readline()
rf.readline()
rf.readline()
while True:
    line = rf.readline()
    if (len(line) == 0):break
    arr = line.replace('\r', '\n').split('\n')[0].split('\t')
    addItem(table.tlist.add(), arr)

f = file('/Users/woodcol/Documents/cocos2dx/demo-datebase/dbp/tab_ChooseAttacker.dbp', 'wb')
f.write(table.SerializeToString())
f.close()
