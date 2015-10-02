# -*- coding: utf-8 -*-
import tab_LevelLockedCharacters_pb2
import codecs

def addItem(item, args):
	item.id = int(args[0])
	item.Comment = args[1]
	item.Level = int(args[2])
	item.Solider = int(args[3])
	item. Tank = int(args[4])
	item.Archibald = int(args[5])
	item.Kamikaze = int(args[6])
	item.Missile = int(args[7])
	item.VoltageTower = int(args[8])
	item.windmill = int(args[9])
	item.fogChamber = int(args[10])
	

table = tab_LevelLockedCharacters_pb2.tab_LevelLockedCharactersTable()
table.tname = 'tab_LevelLockedCharacters.dbp'
rf = codecs.open('/Users/woodcol/Documents/cocos2dx/demo-datebase/txt_protobuf/tab_LevelLockedCharacters.txt', encoding='utf-8')
rf.readline()
rf.readline()
rf.readline()
while True:
    line = rf.readline()
    if (len(line) == 0):break
    arr = line.replace('\r', '\n').split('\n')[0].split('\t')
    addItem(table.tlist.add(), arr)

f = file('/Users/woodcol/Documents/cocos2dx/demo-datebase/dbp/tab_LevelLockedCharacters.dbp', 'wb')
f.write(table.SerializeToString())
f.close()
