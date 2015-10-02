#!/usr/bin/env python
#-*- coding: utf-8 -*-
import codecs
import os,sys
import xlrd
import re
from xlwt.antlr import NULL_TREE_LOOKAHEAD
#将所有Excel文件转为xml文件
reload(sys)
sys.setdefaultencoding( "utf-8" )
xmlDir = "xml"
cppDir = "classfile"
txtDir="txt"
txt_Dir="txt_protobuf"
jsonDir="json"
xmlCoding = 'utf-8'
txtCoding = 'utf-8'
def cur_file_dir():
    #获取脚本路径
    path = sys.path[0]
    #判断为脚本文件还是py2exe编译后的文件，如果是脚本文件，则返回的是脚本的目录，如果是py2exe编译后的文件，则返回的是编译后的文件路径
    if os.path.isdir(path):
        return path
    elif os.path.isfile(path):
        return os.path.dirname(path)
#文件夹删除
def cleanDir(sec):
    for item in os.listdir(sec):
        if (item.find('google') != -1):continue
        itemsrc=os.path.join(sec, item)
        delete_file_folder(itemsrc)
def delete_file_folder(src):
    if os.path.isfile(src):
        try:
            if (src.find('__init__.') == -1):
                os.remove(src)
        except:
            pass
    elif os.path.isdir(src):
        for item in os.listdir(src):
            itemsrc=os.path.join(src,item)
            delete_file_folder(itemsrc) 
        try:
            os.rmdir(src)
        except:
            pass
    return 1
#获取文本的当前路径
txtExcelDir = str(cur_file_dir())
def DirCheck(fullfilename,Dirs): 
    alltxtfile = []   
    for root, dirs, files in os.walk(txtExcelDir):
        for name in dirs:          
            alltxtfile.append(name)
    if Dirs not in alltxtfile:
        os.mkdir(Dirs)
delete_file_folder(txtExcelDir + os.sep + "file")
delete_file_folder(txtExcelDir + os.sep + "dbp")
delete_file_folder(txtExcelDir + os.sep + "cpp_out")
delete_file_folder(txtExcelDir + os.sep + "python_out")
DirCheck(txtExcelDir,xmlDir)
DirCheck(txtExcelDir,txtDir)
DirCheck(txtExcelDir,txt_Dir)
DirCheck(txtExcelDir,cppDir)
DirCheck(txtExcelDir,jsonDir)
DirCheck(txtExcelDir,"file")
DirCheck(txtExcelDir,"python_out")
DirCheck(txtExcelDir,"cpp_out")
DirCheck(txtExcelDir,"dbp")
DirCheck(txtExcelDir,"txt")
DirCheck(txtExcelDir,"txt_protobuf")
infoDir = os.getcwd() + os.sep + 'txt_protobuf' + os.sep
outDir = os.getcwd() + os.sep + 'file' + os.sep
pythonOutDir = os.getcwd() + os.sep + 'python_out' + os.sep
cppOutDir = os.getcwd() + os.sep + 'cpp_out' + os.sep
dbpDir = os.getcwd() + os.sep + 'dbp' + os.sep
fileList = os.listdir(infoDir)
#将数据表转换为txt文本文件
def conventToTxt(fullfilename):
    wb = xlrd.open_workbook(fullfilename)

    for sheetName in wb.sheet_names():
        if sheetName[:3]=="tab":
            savePaths = txtExcelDir + os.sep + "txt"
            savefilenames = os.path.basename(fullfilename)
            txtFile = codecs.open(savePaths + os.sep + sheetName + ".txt",'w',encoding='utf-8')
            sheet = wb.sheet_by_name(sheetName)
            for i in range(0,sheet.ncols):            
                if sheet.cell(2,i).value=='':
                    ##print sheet.nrows,',',sheet.ncols,',',len(sheet.cell(2,sheet.ncols-1).value)
                    nclows=i
                    break
                else:
                    nclows=sheet.ncols               
            for rownum in range(0,sheet.nrows):
                for nnumber in range(0,nclows):
                    v1=sheet.cell(rownum,nnumber).value
                    if (type(v1)==float):
                        v1=str(v1)
                        v1=re.sub('\.0*$', "", v1)
                        txtFile.write(v1)
                    else:
                        txtFile.write(v1)
                    if nnumber != nclows:
                        txtFile.write('\t')
                txtFile.write('\n')
            txtFile.close()
#将excel转换为protobuf可使用类型的txt文件-文件夹为txt-protobuf
def conventToTxt_Protobuf(fullfilename):
    wb = xlrd.open_workbook(fullfilename)

    for sheetName in wb.sheet_names():
        if sheetName[:3]=="tab":
            savePaths = txtExcelDir + os.sep + "txt_protobuf"
            savefilenames = os.path.basename(fullfilename)
            txtFile = codecs.open(savePaths + os.sep + sheetName + ".txt",'w',encoding='utf-8')
            sheet = wb.sheet_by_name(sheetName)
            for i in range(0,sheet.ncols):            
                if sheet.cell(2,i).value=='':
                    ##print sheet.nrows,',',sheet.ncols,',',len(sheet.cell(2,sheet.ncols-1).value)
                    nclows=i
                    break
                else:
                    nclows=sheet.ncols               
            for rownum in range(0,sheet.nrows):
                for nnumber in range(0,nclows):
                    v1=sheet.cell(rownum,nnumber).value
                    if (type(v1)==float):
                        v1=str(v1)
                        v1=re.sub('\.0*$', "", v1)
                        txtFile.write(v1)
                    elif(v1=="int"):
                        v1="int32"
                        txtFile.write(v1)
                    else:
                        txtFile.write(v1)
                    if nnumber != nclows:
                        txtFile.write('\t')
                txtFile.write('\n')
            txtFile.close()
#将EXCEL表转换为json文件
def ExcelToJson(fullfilename):
    wb = xlrd.open_workbook(fullfilename)  
    for sheetName in wb.sheet_names():
        if sheetName[:3]=="tab":
            savePaths = txtExcelDir + os.sep + "json"
            savefilenames = os.path.basename(fullfilename)
            f = codecs.open(savePaths + os.sep + sheetName + ".json",'w',encoding='utf-8')
            sheet = wb.sheet_by_name(sheetName)
            for i in range(0,sheet.ncols):            
                if sheet.cell(2,i).value=='':
                ##print sheet.nrows,',',sheet.ncols,',',len(sheet.cell(2,sheet.ncols-1).value)
                    nclows=i
                    break
                else:
                    nclows=sheet.ncols 
            f.write(u"{\n\t\"list\":[\n")
            for r in range(0,sheet.nrows-1):
                f.write(u"\t\t{ ")
                for c in range(nclows):
                    strCellValue = u""
                    CellObj = sheet.cell_value(r+1,c)
                    if type(CellObj) == float:
                        strCellValue = str(CellObj)
                        strCellValue=re.sub('\.0*$', "", strCellValue)   
                    elif type(CellObj) == unicode:
                        strCellValue = u"\"" + CellObj + u"\""                                  
                    else:
                        strCellValue =CellObj
                    strTmp = u"\""  + sheet.cell_value(0,c) + u"\":"+ strCellValue
                    if c< nclows-1:
                        strTmp += u", "
                    f.write(strTmp)
                f.write(u" }")
                if r < sheet.nrows-2:
                    f.write(u",")
                f.write(u"\n")
            f.write(u"\t]\n}\n")
            f.close()
            print "Create-----",sheetName + ".json","-----OK"
#将txt转换为Protobuf
def makeProtoFile(fileName):
    #f = file(infoDir + fileName, 'r')
    f = codecs.open(infoDir + fileName, encoding='utf-8')
    e = file(outDir + fileName[:-4] + '.proto', 'w')
    try:
        e.write('message ' + fileName[:-4] + 'Table \n{\n')
        e.write('\toptional string tname = 1;\n')
        e.write('\trepeated ' + fileName[:-4] + ' tlist = 2;\n')
        pyw = file(pythonOutDir + 'Write_' + fileName[:-4] + '.py', 'w')
        e.write('}\n\n')
        line1 = f.readline()
        arr1 = line1.replace('\r', '\n').split('\n')[0].split('\t')
        print arr1
        line2 = f.readline()
        arr2 = line2.replace('\r', '\n').split('\n')[0].split('\t')
        print arr2
        line3 = f.readline()
        arr3 = line3.replace('\r', '\n').split('\n')[0].split('\t')
        print arr3
        j = 0
        e.write('message ' + fileName[:-4] + '\n{\n')
        msg = '\t'
        for i in arr1:
            if (i != ''):
                e.write('\toptional ' + arr3[j] + ' ' + i + ' = ' + str(j + 1) + ';\n')
                if (arr3[j]=="int32"):
                    msg = msg + 'item.' + arr1[j] + ' = int(args[' + str(j) + '])\n\t'
                elif (arr3[j]=="float"):
                    msg = msg + 'item.' + arr1[j] + ' = float(args[' + str(j) + '])\n\t'
                elif (arr3[j]=="double"):
                    msg = msg + 'item.' + arr1[j] + ' = double(args[' + str(j) + '])\n\t'
                #if (arr3[j]=="string"):
                    #msg = msg + 'item.' + arr1[j] + ' = string(args[' + str(j) + '])\n\t'
                elif (arr3[j]=="bool"):
                    msg = msg + 'item.' + arr1[j] + ' = bool(args[' + str(j) + '])\n\t'                  
                else:
                    msg = msg + 'item.' + arr1[j] + ' = args[' + str(j) + ']\n\t'
                
                j = j + 1
        e.write('}')

        pyw.write('# -*- coding: utf-8 -*-\n')
        pyw.write('import ' + fileName[:-4] + '_pb2\nimport codecs\n\n')
        pyw.write('def addItem(item, args):\n')
        pyw.write(msg + '\n\n')
        pyw.write('table = ' + fileName[:-4] + '_pb2.' + fileName[:-4] +'Table()\n')
        pyw.write('table.tname = \'' + fileName[:-4] + '.dbp\'\n')
        pyw.write('rf = codecs.open(\'' + infoDir.replace('\\', '\\\\') + fileName + '\', encoding=\'utf-8\')\n')
        mm = '''rf.readline()\nrf.readline()\nrf.readline()
while True:
    line = rf.readline()
    if (len(line) == 0):break
    arr = line.replace(\'\\r\', \'\\n\').split(\'\\n\')[0].split(\'\\t\')
    addItem(table.tlist.add(), arr)\n'''

        pyw.write(mm)
        pyw.write('\nf = file(\'' + dbpDir.replace('\\', '\\\\') + fileName[:-4]+'.dbp\', \'wb\')\n')
        pyw.write('f.write(table.SerializeToString())\n')
        pyw.write('f.close()\n')
    finally:
        e.close()
        f.close()
        pyw.close()

def makeDBP():
    for item in os.listdir(pythonOutDir):
        if (item.find('Write_') != -1):
            cmd = 'python.exe ' + pythonOutDir + item
            os.system(cmd)
#将txt文本文件转换为xml文件
def conventToxml(fullfilename):
    f = open(fullfilename,'r')
    flines = f.readlines()
    if len(flines) == 1:
        flines = flines[0].replace('\r','\n')
        flines = flines.split('\n')
    print len(flines)
    outcach = "<config>\n"
    tablenameLine = flines[0]
    namelist = tablenameLine.split('\t')
    print "输出:\n"
    for n in range(len(flines)):
        if n > 2:
            tmpli = flines[n]
            print tmpli
            litmplist = tmpli.split('\t')
            outcach += "\t<id>\n"
            for pn in range(len(namelist)):
                nametmx = namelist[pn]
                nametmx = nametmx.replace('\n','')
                nametmx = nametmx.replace('\r','')
                litmplistx = litmplist[pn]
                litmplistx = litmplistx.replace('\n','')
                litmplistx = litmplistx.replace('\r','')
                if nametmx.strip() !='':
                    outstr = "\t\t<"+str(nametmx)+">"+str(litmplistx)+"</"+str(nametmx)+">\n"
                    outcach += outstr
            outcach += "\t</id>\n"
    outcach += "</config>"
    f.close()
    savePath = txtExcelDir + os.sep + "xml"
    savefilename = os.path.basename(fullfilename)
    savena,extfi = os.path.splitext(savefilename)
    print extfi
    codecs.open(savePath + os.sep + savena + ".xml", 'w', encoding='utf-8').write(outcach)
#将xml文件转换为程序文件.cpp .h
def outPutDataClass(dataNamelist):
    datlist = {}
    datdesdic = {}
    #数据类型说明
    typedic = {}
    tabNameList = []
    for n in range(len(dataNamelist)):
        filep = dataNamelist[n]
        savefilename = os.path.basename(filep)
        savena,extfi = os.path.splitext(savefilename)
        tabNameList.append(savena)
        f = open(filep,'r')
        flines = f.readlines();
        f.close()
        if len(flines) == 1:
            flines = flines[0].replace('\r','\n')
            flines = flines.split('\n')
        print len(flines)
        tablenameLine = flines[0]
        namelist = tablenameLine.split('\t')
        decline =flines[1]
        deslist = decline.split('\t')
        typeline = flines[2]
        typelist = typeline.split('\t')
        datdesdic[savena] = deslist
        datlist[savena] = namelist
        typedic[savena] = typelist
    print datlist
    hFileOut = ""
    hFileOut += '''//
//  LocalDataManger.h
//  game1
//  C++单例类模板，非线程安全单例类，并且实例化后会常注内存
//
//  Created by 俊盟科技1 on 8/22/14.
//
//  本地数据管理类
//

#ifndef __game1__LocalDataManger__
#define __game1__LocalDataManger__

#include "cocos2d.h"
#include "LocalDataConfig.h"
using namespace std;
class LocalDataManger:public cocos2d::Ref
{
public:
    static LocalDataManger* sharedLocalDataManger();
    static void destroyInstance();
private:
    /**
     * @js ctor
     */
    LocalDataManger(void);
    /**
     * @js NA
     * @lua NA
     */
    ~LocalDataManger(void);
    
'''
    for t in range(len(tabNameList)):
        nametmp = tabNameList[t]
        nametmp = nametmp.replace('\n','')
        nametmp = nametmp.replace('\r','')
        hFileOut += "    map<int,Config" + nametmp + "DataST>  map" + nametmp + "Data;\n"
    hFileOut += "\n    string getXmlFile(string path);\n"
    hFileOut += '''public:
    
    /**
     * Init LocalDataManger
     */
    virtual bool init();'''
    hFileOut += "\n\n"
    for t in range(len(tabNameList)):
        nametmp = tabNameList[t]
        nametmp = nametmp.replace('\n','')
        nametmp = nametmp.replace('\r','')
        hFileOut += "    void readConfig" + nametmp + "Data();\n"
        hFileOut += "    Config" + nametmp + "DataST  getConfig" + nametmp + "DataST(int ID);\n\n" 
    hFileOut += '''    
};

#endif /* defined(__game1__LocalDataManger__) */'''
    print hFileOut
    cppFileOut = ""
    cppFileOut +='''//
//  LocalDataManger.cpp
//  game1
//
//  Created by 俊盟科技1 on 8/22/14.
//
//

#include "LocalDataManger.h"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"
#include "LocalFileManger.h"
using namespace rapidxml;
using namespace cocos2d;
static LocalDataManger *s_sharedLocalDataManger = nullptr;

LocalDataManger *LocalDataManger::sharedLocalDataManger()
{
    if (s_sharedLocalDataManger == nullptr)
    {
        s_sharedLocalDataManger = new LocalDataManger();
        if (!s_sharedLocalDataManger || !s_sharedLocalDataManger->init())
        {
            CC_SAFE_DELETE(s_sharedLocalDataManger);
        }
    }
    return s_sharedLocalDataManger;
}

void LocalDataManger::destroyInstance()
{
    
    CC_SAFE_RELEASE_NULL(s_sharedLocalDataManger);
}

LocalDataManger::LocalDataManger(void)
{
  
}

LocalDataManger::~LocalDataManger(void)
{
   
}


bool LocalDataManger::init()
{
    bool bRet = false;
    do
    {
'''
    for n in range(len(tabNameList)):
        nametmp = tabNameList[n]
        nametmp = nametmp.replace('\n','')
        nametmp = nametmp.replace('\r','')
        cppFileOut += "        map" + nametmp +"Data.clear();\n"
    cppFileOut += "#if 1\n"
    for n in range(len(tabNameList)):
        nametmp = tabNameList[n]
        nametmp = nametmp.replace('\n','')
        nametmp = nametmp.replace('\r','')
        cppFileOut += "        readConfig" + nametmp + "Data();\n"
    cppFileOut += "#endif\n"
    cppFileOut += '''        bRet = true;
    }
    while (0);
    
    return bRet;
}'''
    for n in range(len(tabNameList)):
        nametmp = tabNameList[n]
        nametmp = nametmp.replace('\n','')
        nametmp = nametmp.replace('\r','')
        cppFileOut += "\n//"+ nametmp
        cppFileOut += "\nvoid LocalDataManger::readConfig" + nametmp + "Data()\n{\n"
        cppFileOut += "    if(!map" + nametmp + "Data.empty()) {\n        return;\n    }\n"
        cppFileOut += "    //rapidxml\n    string xmlfile = getXmlFile(\"xml/"+ nametmp + ".xml\");\n"
        cppFileOut += '''    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
'''
        tablist = datlist[nametmp]
        typlist = typedic[nametmp]
        for xn in range(len(tablist)):
            tabtmp = tablist[xn]
            tabtmp = tabtmp.replace('\n','')
            tabtmp = tabtmp.replace('\r','')
            if tabtmp.strip() !='':
                cppFileOut += "        xml_node<> *" + tabtmp +"x = node->first_node(\""+ tabtmp +"\");\n"
        cppFileOut += "        Config" + nametmp + "DataST st;\n\n"
        for xn in range(len(tablist)):
            tabtmp = tablist[xn]
            tabtmp = tabtmp.replace('\n','')
            tabtmp = tabtmp.replace('\r','')
            if xn == 0:
                cppFileOut += "        st.ID = atoi(" + tabtmp + "x->value());\n"
            else:
                typlistx = typlist[xn]
                typlistx = typlistx.replace('\n','')
                typlistx = typlistx.replace('\r','')
                if typlistx == "int":
                    cppFileOut += "        st." + tabtmp + " = atoi(" + tabtmp +"x->value());\n"
                elif typlistx == "float":
                    cppFileOut += "        st." + tabtmp + " = atof(" + tabtmp +"x->value());\n"
                elif typlistx == "string":
                    cppFileOut += "        st." + tabtmp + " = " + tabtmp +"x->value();\n"
                elif typlistx == "bool":
                    cppFileOut += "        st." + tabtmp + " = atoi(" + tabtmp +"x->value());\n"
        cppFileOut += "\n        map" + nametmp + "Data[st.ID] = st;\n    }\n}\n"
        cppFileOut += "Config" + nametmp + "DataST LocalDataManger::getConfig" + nametmp + "DataST(int ID)\n{\n    return map" + nametmp +"Data[ID];\n}\n"
    cppFileOut += '''string LocalDataManger::getXmlFile(string path)
{
    string file = FileUtils::getInstance()->getStringFromFile(path);
    log("file size is %d",(int)file.size());
    return file;
}'''
    print cppFileOut
    
    configDataOut = ""
    configDataOut += '''//
//  LocalDataConfig.h
//  game1
//  使用结构体来进行游戏属性存储会比较方便快捷
//
//  Created by 俊盟科技1 on 8/22/14.
//
//

#ifndef game1_LocalDataConfig_h
#define game1_LocalDataConfig_h
#include "cocos2d.h"
using namespace std;

//示例宏定义，不使用时可删除
#define ktestWar 1

'''
    for n in range(len(tabNameList)):
        nametmp = tabNameList[n]
        tablist = datlist[nametmp]
        disdlist = datdesdic[nametmp]
        typlist = typedic[nametmp]
        configDataOut += "struct "+ nametmp + "DataStruct\n{\n"
        nametmp = nametmp.replace('\n','')
        nametmp = nametmp.replace('\r','')
        for m in range(len(tablist)):
            tabtmp = tablist[m]
            tabtmp = tabtmp.replace('\n','')
            tabtmp = tabtmp.replace('\r','')
            destmp = disdlist[m]
            destmp = destmp.replace('\n','')
            destmp = destmp.replace('\r','')
            typetmp = typlist[m]
            typetmp = typetmp.replace('\n','')
            typetmp = typetmp.replace('\r','')
            if m == 0:
                configDataOut += "    int ID = 0;       //" + destmp +" \n"
            else:
                if typetmp == "int":
                    configDataOut += "    int "+ tabtmp + " = 0;        //" + destmp +" \n"
                elif typetmp == "float":
                    configDataOut += "    float "+ tabtmp + " = 0.0f;        //" + destmp +" \n"
                elif typetmp == "string":
                    configDataOut += "    string "+ tabtmp + " = \"\";        //" + destmp +" \n"
                elif typetmp == "bool":
                    configDataOut += "    bool "+ tabtmp + " = false;        //" + destmp +" \n"
#                else:
#                    configDataOut += "    string "+ tabtmp + " = \"\";        //" + destmp +" \n"
        configDataOut += "};\ntypedef struct " + nametmp + "DataStruct Config" + nametmp + "DataST;\n\n"
    configDataOut += "\n#endif"
    print configDataOut
    savePath = txtExcelDir + os.sep + cppDir
#    savefilename = "LocalDataManger"
    codecs.open(savePath + os.sep + "LocalDataManger.h", 'w', encoding='utf-8').write(hFileOut)
    codecs.open(savePath + os.sep + "LocalDataManger.cpp", 'w', encoding='utf-8').write(cppFileOut)
    codecs.open(savePath + os.sep + "LocalDataConfig.h", 'w', encoding='utf-8').write(configDataOut)
#主函数
print(txtExcelDir + os.sep + "txt")
print(txtExcelDir + os.sep + "txt_protobuf")
cleanDir(pythonOutDir) #clean python proto dir
cleanDir(cppOutDir) #clean cpp proto dir
cleanDir(outDir) #clean proto output dir
def main():
    print txtExcelDir
    alltxtfile = []
    for root, dirs, files in os.walk(txtExcelDir):
        for f in files:
            if f.lower().endswith('.xlsx') or f.lower().endswith('.xls'):
                ffilename = os.path.join(root, f)
                conventToTxt(ffilename)
                conventToTxt_Protobuf(ffilename)               
                ExcelToJson(ffilename)
    for roots, dirss, filess in os.walk(txtExcelDir + os.sep + "txt"):
        for ff in filess:
            if ff.lower().endswith('.txt') and ff[:3]=='tab':
                filename = os.path.join(roots, ff)
                conventToxml(filename)
                alltxtfile.append(filename)
        outPutDataClass(alltxtfile)
    for txtFile in fileList:
        if txtFile[-4:] == '.txt':
            print(txtFile)
            makeProtoFile(txtFile)
if __name__ == '__main__':
    # process_bak_files(action='clear')
    main()
    cppCmd = 'protoc.exe --cpp_out=' + cppOutDir + ' --proto_path=' + outDir + ' ' + outDir + '*.proto' #define cpp cmd
    pyCmd = 'protoc.exe --python_out=' + pythonOutDir + ' --proto_path=' + outDir + ' ' + outDir + '*.proto' #define py cmd
    pyresult = os.system(pyCmd) #make proto.py files
    cppresult = os.system(cppCmd) #make proto.cc files
    if pyresult == 0:
        makeDBP()
        print '*******************Conversion success!!!*********************'
        if(delete_file_folder(txtExcelDir + os.sep + "txt_protobuf") and delete_file_folder(txtExcelDir + os.sep + "txt") and delete_file_folder(txtExcelDir + os.sep + "python_out")):
            print '------****---------rmdir successful!!!------------****-------'
        else:
            print("******************----rmdir failed!!!----********************")
            raw_input()
            exit(0)
#回车结束
print '****Prease    <Enter> to close it,thanks for use  ^-^ !!!****'
raw_input()
exit(0)
