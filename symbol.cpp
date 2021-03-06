#include"symbol.hpp" 

symbolTables::symbolTables(){
    symbolTable table;
    string* temp = new string("golbal");
    table.scopeName = temp;
    tables.push_back(table);
}

void symbolTables::push(string* name){
    symbolTable table;
    table.scopeName = name;
    tables.push_back(table);
}

void symbolTables::pop(){
    dump();
    tables.pop_back();
}

void symbolTables::dump(){

    cout << "=================dump=================\n\n";
    cout << "===" << *tables.back().scopeName << "===\n";

    for(int i = 0; i < tables.back().table_datas.size(); i++){
        symbolTable_data temp = tables.back().table_datas[i];
        cout<< "name : " << *temp.name << "  type : ";

        if(temp.type == TT_FUNC)
            cout << "function\n";
        else if(temp.isArr){
            cout << "array \n";
            // for(int j = 0; j < temp.arrSize; j++)
            //     switch(temp.type)
            //     {
            //     case TT_INT:
            //         cout<< temp.intArr[j] << " ";
            //         break;
            //     case TT_FLOAT:
            //         cout<< temp.floatArr[j] << " ";
            //         break;
            //     case TT_STRING:
            //         cout<< temp.stringArr[j] << " ";
            //         break;
            //     case TT_BOOL:
            //         cout<< temp.boolArr[j] << " ";
            //         break;
            //     }
            // cout << "]\n";
        }
        else if(temp.type == TT_OBJ)
            cout<<"object\n";
        else{
            cout<< "variable\n";
            // switch(temp.type)
            // {
            // case TT_INT:
            //     temp.isInit == true ? cout << temp.intVal << "\n" : cout << "NULL\n";
            //     break;
            // case TT_FLOAT:
            //     temp.isInit == true ? cout << temp.floatVal << "\n" : cout << "NULL\n";
            //     break;
            // case TT_STRING:
            //     temp.isInit == true ? cout << *temp.stringVal << "\n" : cout << "NULL\n";
            //     break;
            // case TT_BOOL:
            //     temp.isInit == true ? cout << temp.boolVal << "\n" : cout << "NULL\n";
            //     break;
            // }
        }
    }
    cout << "===" << *tables.back().scopeName << " end===\n";
}

symbolTable_data symbolTables::lookup_all(string* name){
    string temp_name = *name;
    for(int i = tables.size()-1 ; i > 0; i--)
        for(int j = 0; j< tables[i].table_datas.size(); j++){
            string data_name = *tables[i].table_datas[j].name;
            if(data_name == temp_name)
                return tables[i].table_datas[j];
        }
    symbolTable_data none;
    none.type = TT_NONE;
    return none;
}

symbolTable_data symbolTables::lookup_current(string* name){
    for(int i = 0; i < tables.back().table_datas.size(); i++)
        if(tables.back().table_datas[i].name == name)
            return tables.back().table_datas[i];
    symbolTable_data none;
    none.type = TT_NONE;
    return none;
}

bool symbolTables::add(symbolTable_data new_data){
    if(lookup_current(new_data.name).type == TT_NONE)
        tables.back().table_datas.push_back(new_data);
    else
        return false;
    return true;
}

bool symbolTables::isGlobal(){
    if(tables.size() == 2)
        return true;
    else
        return false;
}

bool symbolTables::update(symbolTable_data new_data){
    for(int i = tables.size()-1 ; i >= 0; i--)
        for(int j = 0; j< tables[i].table_datas.size(); j++)
            if(tables[i].table_datas[j].name == new_data.name){
                if(tables[i].table_datas[j].isConst == false){
                    tables[i].table_datas[j] = new_data;
                    return true;
                }
                else
                    return false;
            }
}
