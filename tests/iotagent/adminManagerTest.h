/**
* Copyright 2015 Telefonica Investigación y Desarrollo, S.A.U
*
* This file is part of iotagent project.
*
* iotagent is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as published
* by the Free Software Foundation, either version 3 of the License,
* or (at your option) any later version.
*
* iotagent is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with iotagent. If not, see http://www.gnu.org/licenses/.
*
* For those usages not covered by the GNU Affero General Public License
* please contact with iot_support at tid dot es
*/
#ifndef SRC_TESTS_ADMIN_MANAGERTEST_H_
#define SRC_TESTS_ADMIN_MANAGERTEST_H_

#include <cppunit/extensions/HelperMacros.h>



#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../mocks/http_mock.h"

#include <boost/property_tree/ptree.hpp>
#include "util/iota_logger.h"
#include "services/admin_mgmt_service.h"
#include "services/admin_service.h"

#include "util/service_collection.h"
#include "ultra_light/ul20_service.h"
#include "baseTest.h"


class AdminManagerTest : public CPPUNIT_NS::TestFixture, public BaseTest {
    CPPUNIT_TEST_SUITE(AdminManagerTest);

    CPPUNIT_TEST(testDeviceToBeAdded);
    CPPUNIT_TEST(testGetEndpointsFromDevices);
    CPPUNIT_TEST(testAddDevicesToEndpoints);
    CPPUNIT_TEST(testGetDevices);
    CPPUNIT_TEST(testMultiplePostsWithResponse);
    CPPUNIT_TEST(testProtocol_ServiceManagement);
    CPPUNIT_TEST(testBADServiceManagement);
    CPPUNIT_TEST(testPostJSONDevices);

    CPPUNIT_TEST(testPutJSONDevice);
    CPPUNIT_TEST(testPutJSONDevice_Wrong);
    CPPUNIT_TEST(testPutProtocolDevice);
    CPPUNIT_TEST(testPostJSONDeviceErrorHandling);

    CPPUNIT_TEST(testNoEndpoints_Bug_IDAS20444);

    CPPUNIT_TEST(testNoDeviceError_Bug_IDAS20463);

    CPPUNIT_TEST(testReregistration_diff_protocol_description);
    CPPUNIT_TEST_SUITE_END();

  public:
    AdminManagerTest();
    virtual ~AdminManagerTest();
    void setUp();
    void tearDown();

    static const int POST_RESPONSE_CODE;
    //GET ALL empty
    static const std::string GET_EMPTY_RESPONSE_DEVICES;
    static const int GET_RESPONSE_CODE;
    static const int DELETE_RESPONSE_CODE;
    static const int GET_RESPONSE_CODE_NOT_FOUND;

    //PROTOCOL
    static const std::string URI_PROTOCOLS;
    static const std::string POST_PROTOCOLS1;
    static const std::string POST_PROTOCOLS2;
    static const std::string POST_PROTOCOLS3;
    static const std::string POST_PROTOCOLS4;
    static const std::string POST_PROTOCOLS2_RERE;
    static const std::string POST_PROTOCOLS2_RERERE;
    static const std::string POST_PROTOCOLS2_RERERE_EMPTY;
    static const std::string GET_PROTOCOLS_RESPONSE;
    static const std::string POST_PROTOCOLS_NO_AGENT;

    // SERVICE_MANAGEMENT
    static const std::string URI_SERVICES_MANAGEMET;
    static const std::string POST_SERVICE_MANAGEMENT1;
    static const std::string PUT_SERVICE_MANAGEMENT1;
    static const std::string POST_SERVICE_MANAGEMENT2;
    static const std::string POST_SERVICE_MANAGEMENT3;
    static const std::string POST_BAD_SERVICE_MANAGEMENT1;
    static const std::string GET_SERVICE_MANAGEMENT_RESPONSE;


    //DEVICE_MANAGEMENT
    static const std::string URI_DEVICES_MANAGEMEMT;
    static const std::string POST_DEVICE_MANAGEMENT1;
    static const std::string GET_DEVICE_MANAGEMENT_RESPONSE;
    static const std::string POST_DEVICE;
    static const std::string POST_DEVICE_NO_PROTOCOL;
    static const std::string PUT_DEVICE;
    static const std::string PUT_DEVICE2;

  protected:

    void testDeviceToBeAdded();
    void testGetEndpointsFromDevices();
    void testAddDevicesToEndpoints();
    void testGetDevices();
    void testMultiplePostsWithResponse();
    void testPostJSONDevices();

    void testPutJSONDevice_Wrong();
    void testPutJSONDevice();

    void testPutProtocolDevice();

    void testPostJSONDeviceErrorHandling();
    void testNoEndpoints_Bug_IDAS20444();
    void testNoDeviceError_Bug_IDAS20463();

    /**
    @IDAS-
    Scenario: changing protocol description
       an iotagent send a registration with a description of protocol
       then you update a new version of iotagent with a new description
       old versions has an error and it produces duplication key error

    Given a iota::AdminManagerService
    When iot manager receive a post protocol with the information of iotagent
      Then a service is created in SRV_MGM table
    when iot manager receive a post protocol from the same iotagent
      the same information instead protocol description
      Then the protocol description is update in SRV_MGM
      **/
    void testReregistration_diff_protocol_description();

  private:
    void cleanDB();

    void testProtocol_ServiceManagement();
    void testBADServiceManagement();

    iota::AdminService* adm;
    iota::AdminManagerService* admMgm;




};

#endif  /* _H */

