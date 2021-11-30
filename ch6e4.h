class Name_value {
public:
    string name;
    int value;
    Name_value(string str, int val)
        :name(str), value(val) { }
};

int main()
try {
    // input
    cout << "Enter name/value pairs, like 'Bob 4'. Terminate with Null 0\n";
    string name = "";
    int value = -1;
    vector<Name_value> nv_vec;
    while (cin>>name>>value && !(name=="Null" && value==0)) {
        for (int i = 0; i<nv_vec.size(); ++i)
            if (name == nv_vec[i].name) error("name occured twice: ",name);
        nv_vec.push_back(Name_value(name,value));
    }

    // print list of name/value pairs
    for (int i = 0; i<nv_vec.size(); ++i) {
        cout << "(" << nv_vec[i].name << ',' << nv_vec[i].value << ")\n";
    }
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
