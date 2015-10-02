# -*- coding: utf-8 -*-
import tab_ScoreRule_pb2
import codecs

def addItem(item, args):
	item.id = int(args[0])
	item.Comment = args[1]
	item.ScoreAddPerPoint = int(args[2])
	item.ScoreAddWin = int(args[3])
	item.CoinsAddWin = int(args[4])
	item.ScoreSubPerPoint = int(args[5])
	item.ScoreSubLose = int(args[6])
	item.CoinsSubLose = int(args[7])
	

table = tab_ScoreRule_pb2.tab_ScoreRuleTable()
table.tname = 'tab_ScoreRule.dbp'
rf = codecs.open('/Users/woodcol/Documents/cocos2dx/demo-datebase/txt_protobuf/tab_ScoreRule.txt', encoding='utf-8')
rf.readline()
rf.readline()
rf.readline()
while True:
    line = rf.readline()
    if (len(line) == 0):break
    arr = line.replace('\r', '\n').split('\n')[0].split('\t')
    addItem(table.tlist.add(), arr)

f = file('/Users/woodcol/Documents/cocos2dx/demo-datebase/dbp/tab_ScoreRule.dbp', 'wb')
f.write(table.SerializeToString())
f.close()
