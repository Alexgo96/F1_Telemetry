#include "../lib/DataFrameReceiver.h" // Assuming you have a header file for DataFrameReceiver
#include <iostream>
#include <iomanip>
#include "../lib/Logger.h"
#include "../lib/ByteConverter.h"
#include "../lib/PacketLapData.h"
#include "../lib/LapData.h"
#include "../lib/PacketHeader.h"
#include "../lib/PacketFactory.h"
#include "../lib/DatabaseManager.h"

int main() {
    const uint8_t NUM_CARS = 20;
    const std::string databaseHost = "127.0.0.1:3307";
    const std::string databaseUser = "root";
    const std::string databasePassword = "admin";
    const std::string databaseName = "F1_TELEMETRY_DATABASE";
    bool driverNamesHardcode = false;

    auto lastInsertTime = std::chrono::steady_clock::now();  // Store start time

    std::cout << "Starting..." << std::endl;

    // HARDCODING DRIVER NAMES (TEMPORAL. WE WILL CHANGE IT)
    driverNamesHardcode = true;
    std::string drivers[NUM_CARS]={"BOT", "MAG", "HAM", "ZHO", "TSU", "GAS", "LEC", "NOR", "PER", "ALB", "SAR", "HUL", "SAI", "OCO", "STR", "RIC", "RUS", "VER", "PIA", "ALO"};
    
    /*if (driverNamesHardcode){
        for(int i = 0; i < NUM_CARS; i++){
            drivers[i] = "driver" +std::to_string(i+1);
        }
    }*/

    Logger::instance().initialize("/home/alex/logfile.txt");
    Logger::instance().log("F1 Telemetry Project Launched");
    Logger::instance().log("Initializing MySQL DB connector...");
    DatabaseManager databaseManager = DatabaseManager(databaseHost, databaseUser, databasePassword, databaseName);
    Logger::instance().log("MySQL DB connector initialized with success");
    // Create an instance of DataFrameReceiver with a specified port
    DataFrameReceiver receiver(12345); // Example port number

    // DEBUG
    //std::string sql_statement_test = "INSERT INTO LAP_DATA_PACKET (m_packetFormat, m_gameYear, m_gameMajorVersion, m_gameMinorVersion, m_packetVersion, m_packetId, m_sessionUID, m_sessionTime, m_frameIdentifier, m_overallFrameIdentifier, m_playerCarIndex, m_secondaryPlayerCarIndex, m_lastLapTimeInMS, m_currentLapTimeInMS, m_sector1TimeInMS, m_sector1TimeMinutes, m_sector2TimeInMS, m_sector2TimeMinutes, m_deltaToCarInFrontInMS, m_deltaToRaceLeaderInMS, m_lapDistance, m_totalDistance, m_safetyCarDelta, m_carPosition, m_currentLapNum, m_pitStatus, m_numPitStops, m_sector, m_currentLapInvalid, m_penalties, m_totalWarnings, m_cornerCuttingWarnings, m_numUnservedDriveThroughPens, m_numUnservedStopGoPens, m_gridPosition, m_driverStatus, m_resultStatus, m_pitLaneTimerActive, m_pitLaneTimeInLaneInMS, m_pitStopTimerInMS, m_pitStopShouldServePen, m_timeTrialPBCarIdx, m_timeTrialRivalCarIdx, m_driverName) VALUES (2023, 23, 1, 2, 1, 7, 2261707984571923106, 123.456, 5678, 91011, 5, 3, 75000, 76000, 30000, 1, 31000, 1, 1500, 2500, 120.789, 345.678, 0.5, 12, 10, 1, 2, 2, 0, 1, 2, 0, 1, 0, 8, 2, 3, 0, 5000, 3000, 0, 6, 9, 'DriverName')";
    //std::cout << "EXECUTING SQL STATEMENT TEST..." << std::endl;
    //databaseManager.executeQuery(sql_statement_test);
    //std::cout << "ENDING SQL STATEMENT TEST" << std::endl;
    //std::string sql_statement_test_2 = "INSERT INTO LAP_DATA_PACKET (m_packetFormat, m_gameYear, m_gameMajorVersion, m_gameMinorVersion, m_packetVersion, m_packetId, m_sessionUID, m_sessionTime, m_frameIdentifier, m_overallFrameIdentifier, m_playerCarIndex, m_secondaryPlayerCarIndex, m_lastLapTimeInMS, m_currentLapTimeInMS, m_sector1TimeInMS, m_sector1TimeMinutes, m_sector2TimeInMS, m_sector2TimeMinutes, m_deltaToCarInFrontInMS, m_deltaToRaceLeaderInMS, m_lapDistance, m_totalDistance, m_safetyCarDelta, m_carPosition, m_currentLapNum, m_pitStatus, m_numPitStops, m_sector, m_currentLapInvalid, m_penalties, m_totalWarnings, m_cornerCuttingWarnings, m_numUnservedDriveThroughPens, m_numUnservedStopGoPens, m_gridPosition, m_driverStatus, m_resultStatus, m_pitLaneTimerActive, m_pitLaneTimeInLaneInMS, m_pitStopTimerInMS, m_pitStopShouldServePen, m_timeTrialPBCarIdx, m_timeTrialRivalCarIdx, m_driverName) VALUES (2023,23,1,21,1,2,2261707984571923106,624.017822,37692,38686,19,255,1697225060,22935,41216,41,22935,0,0,0,0.000000,0.000000,0.000000,231,7,23,1,21,1,2,0,162,250,18,206,109,51,99,292,17436,60,0,0,'driver1')";
    ////std::string sql_statement_test_2 = "INSERT INTO LAP_DATA_PACKET (m_packetFormat, m_gameYear, m_gameMajorVersion, m_gameMinorVersion, m_packetVersion, m_packetId, m_sessionUID, m_sessionTime, m_frameIdentifier, m_overallFrameIdentifier, m_playerCarIndex, m_secondaryPlayerCarIndex, m_lastLapTimeInMS, m_currentLapTimeInMS, m_sector1TimeInMS, m_sector1TimeMinutes, m_sector2TimeInMS, m_sector2TimeMinutes, m_deltaToCarInFrontInMS, m_deltaToRaceLeaderInMS, m_lapDistance, m_totalDistance, m_safetyCarDelta, m_carPosition, m_currentLapNum, m_pitStatus, m_numPitStops, m_sector, m_currentLapInvalid, m_penalties, m_totalWarnings, m_cornerCuttingWarnings, m_numUnservedDriveThroughPens, m_numUnservedStopGoPens, m_gridPosition, m_driverStatus, m_resultStatus, m_pitLaneTimerActive, m_pitLaneTimeInLaneInMS, m_pitStopTimerInMS, m_pitStopShouldServePen, m_timeTrialPBCarIdx, m_timeTrialRivalCarIdx, m_driverName) VALUES (2023,23,1,21,1,2,2261707984571923106,624.017822,37692,38686,19,255,1697225060,22935,41216,41,22935,0,0,0,0.000000,0.000000,231,7,23,1,21,1,2,0,162,250,18,206,109,51,99,292,17436,60,0,0,'driver1')";
    //std::cout << "EXECUTING SQL STATEMENT TEST 2..." << std::endl;
    //databaseManager.executeQuery(sql_statement_test_2);
    std::cout << "ENDING SQL STATEMENT TEST 2";
    // DEBUG END

    // Infinite loop to continuously receive and process data frames
    while (true) {
        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> timer_interval = currentTime - lastInsertTime;

        //Receive data frame
        std::vector<unsigned char> dataFrame = receiver.receiveDataFrame();

        //TEST TO EXTRACT AND TRANSFORM BYTES INFORMATION
        uint16_t packetFormat = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t)); //Deleting the last two bytes
        std::cout << "Received data frame: " << std::to_string(packetFormat) << std::endl;
        uint8_t gameYear = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin()); //Deleting the last byte
        std::cout << "Received data frame: " << std::to_string(gameYear) << std::endl;
        uint8_t gameMajorVersion = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin()); //Deleting the last byte
        std::cout << "Received data frame: " << std::to_string(gameMajorVersion) << std::endl;
        uint8_t gameMinorVersion = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin()); //Deleting the last byte
        uint8_t packetVersion = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin()); //Deleting the last byte
        uint8_t packetId = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin()); //Deleting the last byte
        uint64_t sessionUID = ByteConverter::toUInt64(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint64_t));
        float sessionTime = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        uint32_t frameIdentifier = ByteConverter::toUInt32(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint32_t));
        uint32_t overallFrameIdentifier = ByteConverter::toUInt32(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint32_t));
        uint8_t playerCarIndex = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin()); //Deleting the last byte
        uint8_t secondaryPlayerCarIndex = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin()); //Deleting the last byte

        PacketHeader ph = PacketHeader(packetFormat, gameYear, gameMajorVersion,
                 gameMinorVersion, packetVersion, packetId,
                 sessionUID, sessionTime, frameIdentifier,
                 overallFrameIdentifier, playerCarIndex,
                 secondaryPlayerCarIndex);

        Logger::instance().log("Packet Format = " + std::to_string(packetFormat));
        Logger::instance().log("Game Year = " + std::to_string(gameYear));
        Logger::instance().log("Game Major Version = " + std::to_string(gameMajorVersion));
        Logger::instance().log("Game Minor Version = " + std::to_string(gameMinorVersion));
        Logger::instance().log("Packet Version = " + std::to_string(packetVersion));
        Logger::instance().log("Packet Id = " + std::to_string(packetId));
        Logger::instance().log("Session UID = " + std::to_string(sessionUID));
        Logger::instance().log("Session Time = " + std::to_string(sessionTime));
        Logger::instance().log("Frame Identifier = " + std::to_string(frameIdentifier));
        Logger::instance().log("Overall Frame Identifier = " + std::to_string(overallFrameIdentifier));
        Logger::instance().log("Player Car Index = " + std::to_string(playerCarIndex));
        Logger::instance().log("Secondary Player Car Index = " + std::to_string(secondaryPlayerCarIndex));
        Logger::instance().log("-------------------------------------------------------------------------------------");

        //std::unique_ptr<Packet> packet = PacketFactory::createPacket(packetId, ph, dataFrame, NUM_CARS);

        

        // Classified and insert in database depending on Packet Instance type
        if(packetId == 2 && timer_interval.count() > 3.0){
            std::cout << "PACKET LAP DATA CREATED CORRECTLY" << std::endl;
            //PacketLapData* packetLapData = dynamic_cast<PacketLapData*>(packet.get());
            //PacketLapData* packetLapData = reinterpret_cast<PacketLapData*> (&packet);
            PacketLapData packetLapData = PacketFactory::createPacketLapData(packetId, ph, dataFrame, NUM_CARS);
            std::cout << "AFTER CRATING THE PACKET LAP DATA -> MY CAR POSITION = " << std::to_string(packetLapData.getLapDataPosition(19).getCarPosition()) << std::endl;
            for(int i = 0; i < NUM_CARS; i++){
                // DEBUG
                std::cout << "PACKET FORMAT READING FROM PACKET_LAP_DATA = " << std::to_string(packetFormat)<< std::endl;
                //Insert in database
                std::string sqlStatement = "INSERT INTO LAP_DATA_PACKET ("
                    "m_packetFormat, m_gameYear, m_gameMajorVersion, m_gameMinorVersion, m_packetVersion, m_packetId, "
                    "m_sessionUID, m_sessionTime, m_frameIdentifier, m_overallFrameIdentifier, m_playerCarIndex, m_secondaryPlayerCarIndex, "
                    "m_lastLapTimeInMS, m_currentLapTimeInMS, m_sector1TimeInMS, m_sector1TimeMinutes, m_sector2TimeInMS, m_sector2TimeMinutes, "
                    "m_deltaToCarInFrontInMS, m_deltaToRaceLeaderInMS, m_lapDistance, m_totalDistance, m_safetyCarDelta, m_carPosition, "
                    "m_currentLapNum, m_pitStatus, m_numPitStops, m_sector, m_currentLapInvalid, m_penalties, m_totalWarnings, "
                    "m_cornerCuttingWarnings, m_numUnservedDriveThroughPens, m_numUnservedStopGoPens, m_gridPosition, m_driverStatus, "
                    "m_resultStatus, m_pitLaneTimerActive, m_pitLaneTimeInLaneInMS, m_pitStopTimerInMS, m_pitStopShouldServePen, m_timeTrialPBCarIdx, "
                    "m_timeTrialRivalCarIdx, m_driverName"
                    ") VALUES (" + 
                    std::to_string(packetFormat)+ "," + 
                    std::to_string(gameYear) + "," + 
                    std::to_string(gameMajorVersion) + "," + 
                    std::to_string(gameMinorVersion) + "," + 
                    std::to_string(packetVersion) + "," + 
                    std::to_string(packetId) + "," + 
                    std::to_string(sessionUID) + "," + 
                    std::to_string(sessionTime) + "," + 
                    std::to_string(frameIdentifier) + "," + 
                    std::to_string(overallFrameIdentifier) + "," + 
                    std::to_string(playerCarIndex) + "," + 
                    std::to_string(secondaryPlayerCarIndex) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getLastLapTimeInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getCurrentLapTimeInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getSector1TimeInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getSector1TimeMinutes()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getSector2TimeInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getSector2TimeMinutes()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getDeltaToCarInFrontInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getDeltaToRaceLeaderInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getLapDistance()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getTotalDistance()) + "," +
                    std::to_string(packetLapData.getLapDataPosition(i).getSafetyCarDelta()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getCarPosition()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getCurrentLapNum()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getPitStatus()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getNumPitStops()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getSector()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getCurrentLapInvalid()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getPenalties()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getTotalWarnings()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getCornerCuttingWarnings()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getNumUnservedDriveThroughPens()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getNumUnservedStopGoPens()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getGridPosition()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getDriverStatus()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getResultStatus()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getPitLaneTimerActive()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getPitLaneTimeInLaneInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getPitStopTimerInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getPitStopShouldServePen()) + "," + 
                    std::to_string(packetLapData.getTimeTrialPBCarIdx()) + "," + 
                    std::to_string(packetLapData.getTimeTrialRivalCarIdx()) + ",'" + 
                    drivers[i] + "')";

// Make sure 'drivers[i]' is properly quoted as a string.


                    std::cout << "SQL_STATEMENT = " << sqlStatement << std::endl;

                    databaseManager.executeQuery(sqlStatement);
            }
        }

        // Classified and insert in database depending on Packet Instance type
        if(packetId == 4 && timer_interval.count() > 3.0){
            std::cout << "PACKET LAP DATA CREATED CORRECTLY" << std::endl;
            //PacketLapData* packetLapData = dynamic_cast<PacketLapData*>(packet.get());
            //PacketLapData* packetLapData = reinterpret_cast<PacketLapData*> (&packet);
            PacketLapData packetLapData = PacketFactory::createPacketLapData(packetId, ph, dataFrame, NUM_CARS);
            std::cout << "AFTER CRATING THE PACKET LAP DATA -> MY CAR POSITION = " << std::to_string(packetLapData.getLapDataPosition(19).getCarPosition()) << std::endl;
            for(int i = 0; i < NUM_CARS; i++){
                // DEBUG
                std::cout << "PACKET FORMAT READING FROM PACKET_LAP_DATA = " << std::to_string(packetFormat)<< std::endl;
                //Insert in database
                std::string sqlStatement = "INSERT INTO LAP_DATA_PACKET ("
                    "m_packetFormat, m_gameYear, m_gameMajorVersion, m_gameMinorVersion, m_packetVersion, m_packetId, "
                    "m_sessionUID, m_sessionTime, m_frameIdentifier, m_overallFrameIdentifier, m_playerCarIndex, m_secondaryPlayerCarIndex, "
                    "m_lastLapTimeInMS, m_currentLapTimeInMS, m_sector1TimeInMS, m_sector1TimeMinutes, m_sector2TimeInMS, m_sector2TimeMinutes, "
                    "m_deltaToCarInFrontInMS, m_deltaToRaceLeaderInMS, m_lapDistance, m_totalDistance, m_safetyCarDelta, m_carPosition, "
                    "m_currentLapNum, m_pitStatus, m_numPitStops, m_sector, m_currentLapInvalid, m_penalties, m_totalWarnings, "
                    "m_cornerCuttingWarnings, m_numUnservedDriveThroughPens, m_numUnservedStopGoPens, m_gridPosition, m_driverStatus, "
                    "m_resultStatus, m_pitLaneTimerActive, m_pitLaneTimeInLaneInMS, m_pitStopTimerInMS, m_pitStopShouldServePen, m_timeTrialPBCarIdx, "
                    "m_timeTrialRivalCarIdx, m_driverName"
                    ") VALUES (" + 
                    std::to_string(packetFormat)+ "," + 
                    std::to_string(gameYear) + "," + 
                    std::to_string(gameMajorVersion) + "," + 
                    std::to_string(gameMinorVersion) + "," + 
                    std::to_string(packetVersion) + "," + 
                    std::to_string(packetId) + "," + 
                    std::to_string(sessionUID) + "," + 
                    std::to_string(sessionTime) + "," + 
                    std::to_string(frameIdentifier) + "," + 
                    std::to_string(overallFrameIdentifier) + "," + 
                    std::to_string(playerCarIndex) + "," + 
                    std::to_string(secondaryPlayerCarIndex) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getLastLapTimeInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getCurrentLapTimeInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getSector1TimeInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getSector1TimeMinutes()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getSector2TimeInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getSector2TimeMinutes()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getDeltaToCarInFrontInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getDeltaToRaceLeaderInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getLapDistance()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getTotalDistance()) + "," +
                    std::to_string(packetLapData.getLapDataPosition(i).getSafetyCarDelta()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getCarPosition()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getCurrentLapNum()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getPitStatus()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getNumPitStops()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getSector()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getCurrentLapInvalid()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getPenalties()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getTotalWarnings()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getCornerCuttingWarnings()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getNumUnservedDriveThroughPens()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getNumUnservedStopGoPens()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getGridPosition()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getDriverStatus()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getResultStatus()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getPitLaneTimerActive()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getPitLaneTimeInLaneInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getPitStopTimerInMS()) + "," + 
                    std::to_string(packetLapData.getLapDataPosition(i).getPitStopShouldServePen()) + "," + 
                    std::to_string(packetLapData.getTimeTrialPBCarIdx()) + "," + 
                    std::to_string(packetLapData.getTimeTrialRivalCarIdx()) + ",'" + 
                    drivers[i] + "')";

// Make sure 'drivers[i]' is properly quoted as a string.


                    std::cout << "SQL_STATEMENT = " << sqlStatement << std::endl;

                    databaseManager.executeQuery(sqlStatement);
            }
        }

        // PACKET CAR TELEMTRY DATA
        if(packetId == 6 && timer_interval.count() > 3.0){
            std::cout << "PACKET LAP DATA CREATED CORRECTLY" << std::endl;
            //PacketLapData* packetLapData = dynamic_cast<PacketLapData*>(packet.get());
            //PacketLapData* packetLapData = reinterpret_cast<PacketLapData*> (&packet);
            PacketCarTelemetryData packetCarTelemetryData = PacketFactory::createPacketCarTelemetryData(packetId, ph, dataFrame, NUM_CARS);
            std::cout << "AFTER CRATING THE PACKET CAR TELEMETRY DATA-> MY CAR SPEED = " << std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(19).getSpeed()) << std::endl;
            for(int i = 0; i < NUM_CARS; i++){
                // DEBUG
                std::cout << "PACKET FORMAT READING FROM PACKET_CAR_TELEMETRY_DATA = " << std::to_string(packetFormat)<< std::endl;
                //Insert in database
                std::string sqlStatement = "INSERT INTO CAR_TELEMETRY_DATA_PACKET ("
                    "m_packetFormat, m_gameYear, m_gameMajorVersion, m_gameMinorVersion, m_packetVersion, m_packetId, "
                    "m_sessionUID, m_sessionTime, m_frameIdentifier, m_overallFrameIdentifier, m_playerCarIndex, m_secondaryPlayerCarIndex, "
                    "m_speed, m_throttle, m_steer, m_brake, m_clutch, m_gear, m_engineRPM, m_drs, m_revLightsPercent, m_revLightsBitValue, "
                    "m_brakesTemperatureRL, m_brakesTemperatureRR, m_brakesTemperatureFL, m_brakesTemperatureFR, m_tyresSurfaceTemperatureRL, "
                    "m_tyresSurfaceTemperatureRR, m_tyresSurfaceTemperatureFL, m_tyresSurfaceTemperatureFR, m_tyresInnerTemperatureRL, "
                    "m_tyresInnerTemperatureRR, m_tyresInnerTemperatureFL, m_tyresInnerTemperatureFR, m_engineTemperature, m_tyresPressureRL, "
                    "m_tyresPressureRR, m_tyresPressureFL, m_tyresPressureFR, m_surfaceTypeRL, m_surfaceTypeRR, m_surfaceTypeFL, m_surfaceTypeFR, "
                    "m_mfdPanelIndex, m_mfdPanelIndexSecondaryPlayer, m_suggestedGear, m_driverName"
                    ") VALUES (" + 
                    std::to_string(packetFormat)+ "," + 
                    std::to_string(gameYear) + "," + 
                    std::to_string(gameMajorVersion) + "," + 
                    std::to_string(gameMinorVersion) + "," + 
                    std::to_string(packetVersion) + "," + 
                    std::to_string(packetId) + "," + 
                    std::to_string(sessionUID) + "," + 
                    std::to_string(sessionTime) + "," + 
                    std::to_string(frameIdentifier) + "," + 
                    std::to_string(overallFrameIdentifier) + "," + 
                    std::to_string(playerCarIndex) + "," + 
                    std::to_string(secondaryPlayerCarIndex) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getSpeed()) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getThrottle()) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getSteer()) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getBrake()) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getClutch()) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getGear()) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getENgineRPM()) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getDRS()) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getRevLightsPercent()) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getRevLightsBitValue()) + "," +
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getBrakesTemperature()[0]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getBrakesTemperature()[1]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getBrakesTemperature()[2]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getBrakesTemperature()[3]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getTyresSurfaceTemperature()[0]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getTyresSurfaceTemperature()[1]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getTyresSurfaceTemperature()[2]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getTyresSurfaceTemperature()[3]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getTyresInnerTemperature()[0]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getTyresInnerTemperature()[1]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getTyresInnerTemperature()[2]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getTyresInnerTemperature()[3]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getEngineTemperature()) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getTyresPressure()[0]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getTyresPressure()[1]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getTyresPressure()[2]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getTyresPressure()[3]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getSurfaceType()[0]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getSurfaceType()[1]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getSurfaceType()[2]) + "," + 
                    std::to_string(packetCarTelemetryData.getCarTelemetryDataPosition(i).getSurfaceType()[3]) + "," + 
                    std::to_string(packetCarTelemetryData.getMfdPanelIndex()) + "," + 
                    std::to_string(packetCarTelemetryData.getMfdPanelIndexSecondaryPlayer()) + "," + 
                    std::to_string(packetCarTelemetryData.getSugestedGear()) + ",'" + 
                    drivers[i] + "')";

// Make sure 'drivers[i]' is properly quoted as a string.


                    std::cout << "SQL_STATEMENT = " << sqlStatement << std::endl;

                    databaseManager.executeQuery(sqlStatement);
            }
        }
        //if (std::to_string(packetId) == "2"){
        //    PacketLapData pld = PacketLapData(ph);
        //    pld.createPacketLapData(dataFrame, NUM_CARS);
            ////DEBUG: CREATE LOG FILE
            //Logger::instance().log("******************* LAP DATA PACKET *******************");
            //for(int i = 0; i < NUM_CARS; i++){
            //    Logger::instance().log("Last Lap Time = " + std::to_string((pld.getLapDataPosition(i).getLastLapTimeInMS()));
            //    Logger::instance().log("Time Distance To Race Leader = " + std::to_string(pld.getLapDataPosition(i).getDeltaToRaceLeaderInMS()));
            //    Logger::instance().log("Driver Position = " + std::to_string(pld.getLapDataPosition(i).getCarPosition()));
            //    Logger::instance().log("Current Lap = " + std::to_string(pld.getLapDataPosition(i).getCurrentLapNum()));
            //    Logger::instance().log("-------------------------------------------------------");
            //}
            //Logger::instance().log("*******************************************************");
            //END
        //}
    }

    return 0;
}
