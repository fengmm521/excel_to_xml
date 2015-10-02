# -*- coding: utf-8 -*-
import tab_CharacterAttr_pb2
import codecs

def addItem(item, args):
	item.id = int(args[0])
	item.Comment = args[1]
	item.Level = int(args[2])
	item.Type = int(args[3])
	item.InGameName = int(args[4])
	item.TrainCost = int(args[5])
	item.UpgradeCost = int(args[6])
	item.UpgradeTime = int(args[7])
	item.UpdateDiamond = int(args[8])
	item.Hurt = int(args[9])
	item.Velocity = int(args[10])
	item.Hp = int(args[11])
	item.CostUnit = int(args[12])
	item.FightCapacity = int(args[13])
	

table = tab_CharacterAttr_pb2.tab_CharacterAttrTable()
table.tname = 'tab_CharacterAttr.dbp'
rf = codecs.open('/Users/woodcol/Documents/cocos2dx/demo-datebase/txt_protobuf/tab_CharacterAttr.txt', encoding='utf-8')
rf.readline()
rf.readline()
rf.readline()
while True:
    line = rf.readline()
    if (len(line) == 0):break
    arr = line.replace('\r', '\n').split('\n')[0].split('\t')
    addItem(table.tlist.add(), arr)

f = file('/Users/woodcol/Documents/cocos2dx/demo-datebase/dbp/tab_CharacterAttr.dbp', 'wb')
f.write(table.SerializeToString())
f.close()
