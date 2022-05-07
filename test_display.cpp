#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
#include "/usr/local/cs/cs251/react.h"
#include "state/State.h"

State state;

void test_display() {
  //cerr << "in test display" << endl;
  display(state);
  //cerr << "used display" << endl;
  assert(_global_yaml.size() > 50 /*2000*/);
  //cerr << "asserted size" << endl;
  // assert(_global_mem[state.offset_for_raw_colors()] == 216);
}

int main() {
    //cerr << "in main" << endl;
    _read_global_mem_from_file("state1.txt");
    //cerr << "read global_mem" << endl;
    state.read_from(_global_mem);
    //cerr << "used read_from" << endl;
    ifstream f_label("labels.txt");
    f_label.read(_global_mem + state.label_offset, 4000);
    test_display();
    _write_global_yaml_to_file("react.yaml");
    //cerr << "wrote yaml to react" << endl;
    _write_global_mem_to_file("end_mem");
    //cerr << "wrote global_mem to file" << endl;
    delete _global_mem;
}