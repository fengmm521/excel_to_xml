# -*- coding: utf-8 -*-
import tab_ShieldSkill_pb2
import codecs

def addItem(item, args):
	item.id = int(args[0])
	item.Comment = args[1]
	item.Level = int(args[2])
	item.InGameName = int(args[3])
	item.TrainCost = int(args[4])
	item.UpgradeCost = int(args[5])
	item.UpgradeTime = int(args[6])
	item.UpdateDiamond = int(args[7])
	item.DefenseAdd = int(args[8])
	

table = tab_ShieldSkill_pb2.tab_ShieldSkillTable()
table.tname = 'tab_ShieldSkill.dbp'
rf = codecs.open('/Users/woodcol/Documents/cocos2dx/demo-datebase/txt_protobuf/tab_ShieldSkill.txt', encoding='utf-8')
rf.readline()
rf.readline()
rf.readline()
while True:
    line = rf.readline()
    if (len(line) == 0):break
    arr = line.replace('\r', '\n').split('\n')[0].split('\t')
    addItem(table.tlist.add(), arr)

f = file('/Users/woodcol/Documents/cocos2dx/demo-datebase/dbp/tab_ShieldSkill.dbp', 'wb')
f.write(table.SerializeToString())
f.close()
