# -*- coding: utf-8 -*-
import tab_CharacterShootPatterns_pb2
import codecs

def addItem(item, args):
	item.id = int(args[0])
	item.Comment = args[1]
	item.Type = int(args[2])
	item.LightBullet = int(args[3])
	item.HeavyBullet = int(args[4])
	item.Missile = int(args[5])
	item.Nightning = int(args[6])
	item.Fog = int(args[7])
	item.Wind = int(args[8])
	item.Archibald = int(args[9])
	

table = tab_CharacterShootPatterns_pb2.tab_CharacterShootPatternsTable()
table.tname = 'tab_CharacterShootPatterns.dbp'
rf = codecs.open('/Users/woodcol/Documents/cocos2dx/demo-datebase/txt_protobuf/tab_CharacterShootPatterns.txt', encoding='utf-8')
rf.readline()
rf.readline()
rf.readline()
while True:
    line = rf.readline()
    if (len(line) == 0):break
    arr = line.replace('\r', '\n').split('\n')[0].split('\t')
    addItem(table.tlist.add(), arr)

f = file('/Users/woodcol/Documents/cocos2dx/demo-datebase/dbp/tab_CharacterShootPatterns.dbp', 'wb')
f.write(table.SerializeToString())
f.close()
