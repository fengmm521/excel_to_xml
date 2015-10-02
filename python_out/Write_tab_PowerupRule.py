# -*- coding: utf-8 -*-
import tab_PowerupRule_pb2
import codecs

def addItem(item, args):
	item.id = int(args[0])
	item.Comment = args[1]
	item.Level = int(args[2])
	item.Coins = int(args[3])
	item.CoinLowBound = int(args[4])
	item.CoinUpperBound = int(args[5])
	item.LifePoints = int(args[6])
	item.LifeLowBound = int(args[7])
	item.LifeUpperBound = int(args[8])
	item.Bomb = int(args[9])
	item.Shield = int(args[10])
	item.Life = int(args[11])
	

table = tab_PowerupRule_pb2.tab_PowerupRuleTable()
table.tname = 'tab_PowerupRule.dbp'
rf = codecs.open('/Users/woodcol/Documents/cocos2dx/demo-datebase/txt_protobuf/tab_PowerupRule.txt', encoding='utf-8')
rf.readline()
rf.readline()
rf.readline()
while True:
    line = rf.readline()
    if (len(line) == 0):break
    arr = line.replace('\r', '\n').split('\n')[0].split('\t')
    addItem(table.tlist.add(), arr)

f = file('/Users/woodcol/Documents/cocos2dx/demo-datebase/dbp/tab_PowerupRule.dbp', 'wb')
f.write(table.SerializeToString())
f.close()
