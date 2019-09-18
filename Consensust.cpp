/*
    Copyright (C) 2018-2019 SKALE Labs

    This file is part of skale-consensus.

    skale-consensus is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    skale-consensus is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with skale-consensus.  If not, see <https://www.gnu.org/licenses/>.

    @file Skaled.cpp
    @author Stan Kladko
    @date 2018
*/

#define CATCH_CONFIG_MAIN

#include "thirdparty/catch.hpp"

#include "SkaleCommon.h"
#include "Log.h"
#include "node/ConsensusEngine.h"

#include "time.h"
#include "Consensust.h"

#ifdef GOOGLE_PROFILE
#include <gperftools/heap-profiler.h>
#endif



class StartFromScratch {
public:
    StartFromScratch() {
        system("rm -rf /tmp/*.db");
        Consensust::setConfigDirPath(boost::filesystem::system_complete("."));

#ifdef GOOGLE_PROFILE
        HeapProfilerStart("/tmp/consensusd.profile");
#endif

    };

    ~StartFromScratch() {
#ifdef GOOGLE_PROFILE
        HeapProfilerStop();
#endif
    }
};

uint64_t Consensust::getRunningTime() {
    return runningTimeMs;
}

void Consensust::setRunningTime(uint64_t _runningTimeMs) {
    Consensust::runningTimeMs = _runningTimeMs;
}

uint64_t Consensust::runningTimeMs = RUNNING_TIME_MS;

fs_path Consensust::configDirPath;

const fs_path &Consensust::getConfigDirPath() {
    return configDirPath;
}




void Consensust::setConfigDirPath(const fs_path &_configDirPath) {
    Consensust::configDirPath = _configDirPath;
}


void testLog(const char* message) {
    printf("TEST_LOG: %s\n", message);
}

/*

TEST_CASE("Consensus init destroy", "[consensus-init-destroy]") {
    Consensust::testInit();

    for (int i = 0; i < 10; i++) {


        testLog("Parsing configs");

        ConsensusEngine engine;


        REQUIRE_NOTHROW(engine.parseConfigsAndCreateAllNodes(Consensust::getConfigDirPath()));


        testLog("Starting nodes");


    }

    Consensust::testFinalize();
}

 */




TEST_CASE_METHOD(StartFromScratch, "Run basic consensus", "[consensus-basic]") {


    ConsensusEngine engine;


    testLog("Parsing configs");


    engine.parseConfigsAndCreateAllNodes(Consensust::getConfigDirPath());

    testLog("Starting nodes");


    engine.slowStartBootStrapTest();


    testLog("Running consensus");


    usleep(Consensust::getRunningTime()); /* Flawfinder: ignore */

    assert(engine.nodesCount() > 0);

    assert(engine.getLargestCommittedBlockID() > 0);


    testLog("Exiting gracefully");


    engine.exitGracefully();

    SUCCEED();

}


ConsensusEngine engine;

bool success = false;

void exit_check() {

    sleep(STUCK_TEST_TIME);

    engine.exitGracefully();

}


TEST_CASE_METHOD(StartFromScratch, "Get consensus to stuck", "[consensus-stuck]") {

    testLog("Parsing configs");

    std::thread timer(exit_check);

    try {



        auto startTime = time(NULL);

        engine.parseConfigsAndCreateAllNodes(Consensust::getConfigDirPath());

        engine.slowStartBootStrapTest();

        auto finishTime = time(NULL);

        if (finishTime - startTime < STUCK_TEST_TIME) {
            printf("Consensus did not get stuck");

            REQUIRE(false);
        }


    } catch  (...) {
        timer.join();
    }

    SUCCEED();
}