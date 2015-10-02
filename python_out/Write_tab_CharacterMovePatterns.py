# -*- coding: utf-8 -*-
import tab_CharacterMovePatterns_pb2
import codecs

def addItem(item, args):
	item.id = int(args[0])
	item.Comment = args[1]
	item.Type = int(args[2])
	item.Stable = int(args[3])
	item.Left = int(args[4])
	item.Right = int(args[5])
	item.Up = int(args[6])
	item.Down = int(args[7])
	item.TowardPlayer = int(args[8])
	

table = tab_CharacterMovePatterns_pb2.tab_CharacterMovePatternsTable()
table.tname = 'tab_CharacterMovePatterns.dbp'
rf = codecs.open('/Users/woodcol/Documents/cocos2dx/demo-datebase/txt_protobuf/tab_CharacterMovePatterns.txt', encoding='utf-8')
rf.readline()
rf.readline()
rf.readline()
while True:
    line = rf.readline()
    if (len(line) == 0):break
    arr = line.replace('\r', '\n').split('\n')[0].split('\t')
    addItem(table.tlist.add(), arr)

f = file('/Users/woodcol/Documents/cocos2dx/demo-datebase/dbp/tab_CharacterMovePatterns.dbp', 'wb')
f.write(table.SerializeToString())
f.close()
