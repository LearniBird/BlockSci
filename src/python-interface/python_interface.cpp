//
//  blocksci.cpp
//  BlockReader
//
//  Created by Harry Kalodner on 1/14/17.
//  Copyright © 2017 Harry Kalodner. All rights reserved.
//

#include "optional_py.hpp"
#include "any_script_caster.hpp"
#include "variant_py.hpp"
#include "block_py.hpp"
#include "input_py.hpp"
#include "output_py.hpp"
#include "tx_py.hpp"
#include "cluster_py.hpp"
#include "address_py.hpp"
#include "pubkey_py.hpp"
#include "multisig_py.hpp"
#include "scripthash_py.hpp"
#include "nulldata_py.hpp"
#include "nonstandard_py.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/chrono.h>

namespace py = pybind11;

void init_tx_summary(py::module &m);
void init_blockchain(py::module &m);
void init_ranges(py::module &m);
void init_heuristics(py::module &m);

PYBIND11_MODULE(blocksci_interface, m) {
    auto addressCl = init_address(m);
    init_blockchain(m);
    init_block(m);
    init_tx(m);
    init_tx_summary(m);
    init_input(m);
    init_output(m);
    init_ranges(m);
    init_heuristics(m);
    init_cluster(m);
    init_pubkey(m, addressCl);
    init_multisig(m, addressCl);
    init_scripthash(m, addressCl);
    init_nulldata(m, addressCl);
    init_nonstandard(m, addressCl);
}
