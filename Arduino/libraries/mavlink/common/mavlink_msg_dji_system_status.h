// MESSAGE DJI_SYSTEM_STATUS PACKING

#define MAVLINK_MSG_ID_DJI_SYSTEM_STATUS 164

typedef struct __mavlink_dji_system_status_t
{
 int32_t latitude; ///< Latitude (WGS84), in degrees * 1E7.
 int32_t longitude; ///< Longitude (WGS84), in degrees * 1E7.
 int32_t latitudeHome; ///< Home Latitude (WGS84), in degrees * 1E7.
 int32_t longitudeHome; ///< Home Longitude (WGS84), in degrees * 1E7.
 int32_t altitudeHome; ///< home altitude from barometric sensor plus 20m (meters)
 int32_t altitudeBarometer; ///< Altitude (Barometer), in meters * 1000 (positive for up)
 int32_t altitudeGps; ///< Altitude (WGS84), in meters * 1000 (positive for up).
 int16_t speed; ///< GPS ground speed (m/s * 100).
 int16_t climbSpeedBarometer; ///< Barometer vertical speed (m/s * 100).
 int16_t climbSpeedGps; ///< GPS vertical speed (m/s * 100).
 uint16_t course; ///< Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees.
 uint16_t heading; ///< Compass heading in degrees * 100, 0.0..359.99 degrees (titlt compensated).
 uint16_t headingNc; ///< Compass heading in degrees * 100, 0.0..359.99 degrees (not titlt compensated).
 uint16_t hdop; ///< GPS HDOP horizontal dilution of position in cm (m*100).
 uint16_t vdop; ///< GPS VDOP vertical dilution of position in cm (m*100).
 uint16_t voltageBattery; ///< Battery voltage, in millivolts (1 = 1 millivolt).
 uint16_t currentBattery; ///< Battery current, in milliampere (1 = 1 milliampere).
 uint16_t consumedBattery; ///< Battery current consumed, in milliampere (1 = 1 milliampere).
 uint8_t satellitesVisible; ///< Number of satellites visible. If unknown, set to 255.
 uint8_t fixType; ///< 0-1: no fix, 2: 2D fix, 3: 3D fix, 4: DGPS.
 int8_t pitch; ///< Pitch in degrees.
 int8_t roll; ///< Roll in degrees.
 uint8_t flightMode; ///< 0:manual, 1: GPS, 2: FAILSAFE, 3: ATTI.
} mavlink_dji_system_status_t;

#define MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN 55
#define MAVLINK_MSG_ID_164_LEN 55

#define MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_CRC 99
#define MAVLINK_MSG_ID_164_CRC 99



#define MAVLINK_MESSAGE_INFO_DJI_SYSTEM_STATUS { \
	"DJI_SYSTEM_STATUS", \
	23, \
	{  { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_dji_system_status_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_dji_system_status_t, longitude) }, \
         { "latitudeHome", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_dji_system_status_t, latitudeHome) }, \
         { "longitudeHome", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_dji_system_status_t, longitudeHome) }, \
         { "altitudeHome", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_dji_system_status_t, altitudeHome) }, \
         { "altitudeBarometer", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_dji_system_status_t, altitudeBarometer) }, \
         { "altitudeGps", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_dji_system_status_t, altitudeGps) }, \
         { "speed", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_dji_system_status_t, speed) }, \
         { "climbSpeedBarometer", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_dji_system_status_t, climbSpeedBarometer) }, \
         { "climbSpeedGps", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_dji_system_status_t, climbSpeedGps) }, \
         { "course", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_dji_system_status_t, course) }, \
         { "heading", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_dji_system_status_t, heading) }, \
         { "headingNc", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_dji_system_status_t, headingNc) }, \
         { "hdop", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_dji_system_status_t, hdop) }, \
         { "vdop", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_dji_system_status_t, vdop) }, \
         { "voltageBattery", NULL, MAVLINK_TYPE_UINT16_T, 0, 44, offsetof(mavlink_dji_system_status_t, voltageBattery) }, \
         { "currentBattery", NULL, MAVLINK_TYPE_UINT16_T, 0, 46, offsetof(mavlink_dji_system_status_t, currentBattery) }, \
         { "consumedBattery", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_dji_system_status_t, consumedBattery) }, \
         { "satellitesVisible", NULL, MAVLINK_TYPE_UINT8_T, 0, 50, offsetof(mavlink_dji_system_status_t, satellitesVisible) }, \
         { "fixType", NULL, MAVLINK_TYPE_UINT8_T, 0, 51, offsetof(mavlink_dji_system_status_t, fixType) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT8_T, 0, 52, offsetof(mavlink_dji_system_status_t, pitch) }, \
         { "roll", NULL, MAVLINK_TYPE_INT8_T, 0, 53, offsetof(mavlink_dji_system_status_t, roll) }, \
         { "flightMode", NULL, MAVLINK_TYPE_UINT8_T, 0, 54, offsetof(mavlink_dji_system_status_t, flightMode) }, \
         } \
}


/**
 * @brief Pack a dji_system_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param latitude Latitude (WGS84), in degrees * 1E7.
 * @param longitude Longitude (WGS84), in degrees * 1E7.
 * @param latitudeHome Home Latitude (WGS84), in degrees * 1E7.
 * @param longitudeHome Home Longitude (WGS84), in degrees * 1E7.
 * @param altitudeHome home altitude from barometric sensor plus 20m (meters)
 * @param altitudeBarometer Altitude (Barometer), in meters * 1000 (positive for up)
 * @param altitudeGps Altitude (WGS84), in meters * 1000 (positive for up).
 * @param speed GPS ground speed (m/s * 100).
 * @param climbSpeedBarometer Barometer vertical speed (m/s * 100).
 * @param climbSpeedGps GPS vertical speed (m/s * 100).
 * @param satellitesVisible Number of satellites visible. If unknown, set to 255.
 * @param fixType 0-1: no fix, 2: 2D fix, 3: 3D fix, 4: DGPS.
 * @param course Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees.
 * @param heading Compass heading in degrees * 100, 0.0..359.99 degrees (titlt compensated).
 * @param headingNc Compass heading in degrees * 100, 0.0..359.99 degrees (not titlt compensated).
 * @param hdop GPS HDOP horizontal dilution of position in cm (m*100).
 * @param vdop GPS VDOP vertical dilution of position in cm (m*100).
 * @param pitch Pitch in degrees.
 * @param roll Roll in degrees.
 * @param voltageBattery Battery voltage, in millivolts (1 = 1 millivolt).
 * @param currentBattery Battery current, in milliampere (1 = 1 milliampere).
 * @param consumedBattery Battery current consumed, in milliampere (1 = 1 milliampere).
 * @param flightMode 0:manual, 1: GPS, 2: FAILSAFE, 3: ATTI.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dji_system_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t latitude, int32_t longitude, int32_t latitudeHome, int32_t longitudeHome, int32_t altitudeHome, int32_t altitudeBarometer, int32_t altitudeGps, int16_t speed, int16_t climbSpeedBarometer, int16_t climbSpeedGps, uint8_t satellitesVisible, uint8_t fixType, uint16_t course, uint16_t heading, uint16_t headingNc, uint16_t hdop, uint16_t vdop, int8_t pitch, int8_t roll, uint16_t voltageBattery, uint16_t currentBattery, uint16_t consumedBattery, uint8_t flightMode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN];
	_mav_put_int32_t(buf, 0, latitude);
	_mav_put_int32_t(buf, 4, longitude);
	_mav_put_int32_t(buf, 8, latitudeHome);
	_mav_put_int32_t(buf, 12, longitudeHome);
	_mav_put_int32_t(buf, 16, altitudeHome);
	_mav_put_int32_t(buf, 20, altitudeBarometer);
	_mav_put_int32_t(buf, 24, altitudeGps);
	_mav_put_int16_t(buf, 28, speed);
	_mav_put_int16_t(buf, 30, climbSpeedBarometer);
	_mav_put_int16_t(buf, 32, climbSpeedGps);
	_mav_put_uint16_t(buf, 34, course);
	_mav_put_uint16_t(buf, 36, heading);
	_mav_put_uint16_t(buf, 38, headingNc);
	_mav_put_uint16_t(buf, 40, hdop);
	_mav_put_uint16_t(buf, 42, vdop);
	_mav_put_uint16_t(buf, 44, voltageBattery);
	_mav_put_uint16_t(buf, 46, currentBattery);
	_mav_put_uint16_t(buf, 48, consumedBattery);
	_mav_put_uint8_t(buf, 50, satellitesVisible);
	_mav_put_uint8_t(buf, 51, fixType);
	_mav_put_int8_t(buf, 52, pitch);
	_mav_put_int8_t(buf, 53, roll);
	_mav_put_uint8_t(buf, 54, flightMode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN);
#else
	mavlink_dji_system_status_t packet;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.latitudeHome = latitudeHome;
	packet.longitudeHome = longitudeHome;
	packet.altitudeHome = altitudeHome;
	packet.altitudeBarometer = altitudeBarometer;
	packet.altitudeGps = altitudeGps;
	packet.speed = speed;
	packet.climbSpeedBarometer = climbSpeedBarometer;
	packet.climbSpeedGps = climbSpeedGps;
	packet.course = course;
	packet.heading = heading;
	packet.headingNc = headingNc;
	packet.hdop = hdop;
	packet.vdop = vdop;
	packet.voltageBattery = voltageBattery;
	packet.currentBattery = currentBattery;
	packet.consumedBattery = consumedBattery;
	packet.satellitesVisible = satellitesVisible;
	packet.fixType = fixType;
	packet.pitch = pitch;
	packet.roll = roll;
	packet.flightMode = flightMode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DJI_SYSTEM_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN);
#endif
}

/**
 * @brief Pack a dji_system_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param latitude Latitude (WGS84), in degrees * 1E7.
 * @param longitude Longitude (WGS84), in degrees * 1E7.
 * @param latitudeHome Home Latitude (WGS84), in degrees * 1E7.
 * @param longitudeHome Home Longitude (WGS84), in degrees * 1E7.
 * @param altitudeHome home altitude from barometric sensor plus 20m (meters)
 * @param altitudeBarometer Altitude (Barometer), in meters * 1000 (positive for up)
 * @param altitudeGps Altitude (WGS84), in meters * 1000 (positive for up).
 * @param speed GPS ground speed (m/s * 100).
 * @param climbSpeedBarometer Barometer vertical speed (m/s * 100).
 * @param climbSpeedGps GPS vertical speed (m/s * 100).
 * @param satellitesVisible Number of satellites visible. If unknown, set to 255.
 * @param fixType 0-1: no fix, 2: 2D fix, 3: 3D fix, 4: DGPS.
 * @param course Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees.
 * @param heading Compass heading in degrees * 100, 0.0..359.99 degrees (titlt compensated).
 * @param headingNc Compass heading in degrees * 100, 0.0..359.99 degrees (not titlt compensated).
 * @param hdop GPS HDOP horizontal dilution of position in cm (m*100).
 * @param vdop GPS VDOP vertical dilution of position in cm (m*100).
 * @param pitch Pitch in degrees.
 * @param roll Roll in degrees.
 * @param voltageBattery Battery voltage, in millivolts (1 = 1 millivolt).
 * @param currentBattery Battery current, in milliampere (1 = 1 milliampere).
 * @param consumedBattery Battery current consumed, in milliampere (1 = 1 milliampere).
 * @param flightMode 0:manual, 1: GPS, 2: FAILSAFE, 3: ATTI.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dji_system_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t latitude,int32_t longitude,int32_t latitudeHome,int32_t longitudeHome,int32_t altitudeHome,int32_t altitudeBarometer,int32_t altitudeGps,int16_t speed,int16_t climbSpeedBarometer,int16_t climbSpeedGps,uint8_t satellitesVisible,uint8_t fixType,uint16_t course,uint16_t heading,uint16_t headingNc,uint16_t hdop,uint16_t vdop,int8_t pitch,int8_t roll,uint16_t voltageBattery,uint16_t currentBattery,uint16_t consumedBattery,uint8_t flightMode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN];
	_mav_put_int32_t(buf, 0, latitude);
	_mav_put_int32_t(buf, 4, longitude);
	_mav_put_int32_t(buf, 8, latitudeHome);
	_mav_put_int32_t(buf, 12, longitudeHome);
	_mav_put_int32_t(buf, 16, altitudeHome);
	_mav_put_int32_t(buf, 20, altitudeBarometer);
	_mav_put_int32_t(buf, 24, altitudeGps);
	_mav_put_int16_t(buf, 28, speed);
	_mav_put_int16_t(buf, 30, climbSpeedBarometer);
	_mav_put_int16_t(buf, 32, climbSpeedGps);
	_mav_put_uint16_t(buf, 34, course);
	_mav_put_uint16_t(buf, 36, heading);
	_mav_put_uint16_t(buf, 38, headingNc);
	_mav_put_uint16_t(buf, 40, hdop);
	_mav_put_uint16_t(buf, 42, vdop);
	_mav_put_uint16_t(buf, 44, voltageBattery);
	_mav_put_uint16_t(buf, 46, currentBattery);
	_mav_put_uint16_t(buf, 48, consumedBattery);
	_mav_put_uint8_t(buf, 50, satellitesVisible);
	_mav_put_uint8_t(buf, 51, fixType);
	_mav_put_int8_t(buf, 52, pitch);
	_mav_put_int8_t(buf, 53, roll);
	_mav_put_uint8_t(buf, 54, flightMode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN);
#else
	mavlink_dji_system_status_t packet;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.latitudeHome = latitudeHome;
	packet.longitudeHome = longitudeHome;
	packet.altitudeHome = altitudeHome;
	packet.altitudeBarometer = altitudeBarometer;
	packet.altitudeGps = altitudeGps;
	packet.speed = speed;
	packet.climbSpeedBarometer = climbSpeedBarometer;
	packet.climbSpeedGps = climbSpeedGps;
	packet.course = course;
	packet.heading = heading;
	packet.headingNc = headingNc;
	packet.hdop = hdop;
	packet.vdop = vdop;
	packet.voltageBattery = voltageBattery;
	packet.currentBattery = currentBattery;
	packet.consumedBattery = consumedBattery;
	packet.satellitesVisible = satellitesVisible;
	packet.fixType = fixType;
	packet.pitch = pitch;
	packet.roll = roll;
	packet.flightMode = flightMode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DJI_SYSTEM_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN);
#endif
}

/**
 * @brief Encode a dji_system_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dji_system_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dji_system_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dji_system_status_t* dji_system_status)
{
	return mavlink_msg_dji_system_status_pack(system_id, component_id, msg, dji_system_status->latitude, dji_system_status->longitude, dji_system_status->latitudeHome, dji_system_status->longitudeHome, dji_system_status->altitudeHome, dji_system_status->altitudeBarometer, dji_system_status->altitudeGps, dji_system_status->speed, dji_system_status->climbSpeedBarometer, dji_system_status->climbSpeedGps, dji_system_status->satellitesVisible, dji_system_status->fixType, dji_system_status->course, dji_system_status->heading, dji_system_status->headingNc, dji_system_status->hdop, dji_system_status->vdop, dji_system_status->pitch, dji_system_status->roll, dji_system_status->voltageBattery, dji_system_status->currentBattery, dji_system_status->consumedBattery, dji_system_status->flightMode);
}

/**
 * @brief Encode a dji_system_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dji_system_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dji_system_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dji_system_status_t* dji_system_status)
{
	return mavlink_msg_dji_system_status_pack_chan(system_id, component_id, chan, msg, dji_system_status->latitude, dji_system_status->longitude, dji_system_status->latitudeHome, dji_system_status->longitudeHome, dji_system_status->altitudeHome, dji_system_status->altitudeBarometer, dji_system_status->altitudeGps, dji_system_status->speed, dji_system_status->climbSpeedBarometer, dji_system_status->climbSpeedGps, dji_system_status->satellitesVisible, dji_system_status->fixType, dji_system_status->course, dji_system_status->heading, dji_system_status->headingNc, dji_system_status->hdop, dji_system_status->vdop, dji_system_status->pitch, dji_system_status->roll, dji_system_status->voltageBattery, dji_system_status->currentBattery, dji_system_status->consumedBattery, dji_system_status->flightMode);
}

/**
 * @brief Send a dji_system_status message
 * @param chan MAVLink channel to send the message
 *
 * @param latitude Latitude (WGS84), in degrees * 1E7.
 * @param longitude Longitude (WGS84), in degrees * 1E7.
 * @param latitudeHome Home Latitude (WGS84), in degrees * 1E7.
 * @param longitudeHome Home Longitude (WGS84), in degrees * 1E7.
 * @param altitudeHome home altitude from barometric sensor plus 20m (meters)
 * @param altitudeBarometer Altitude (Barometer), in meters * 1000 (positive for up)
 * @param altitudeGps Altitude (WGS84), in meters * 1000 (positive for up).
 * @param speed GPS ground speed (m/s * 100).
 * @param climbSpeedBarometer Barometer vertical speed (m/s * 100).
 * @param climbSpeedGps GPS vertical speed (m/s * 100).
 * @param satellitesVisible Number of satellites visible. If unknown, set to 255.
 * @param fixType 0-1: no fix, 2: 2D fix, 3: 3D fix, 4: DGPS.
 * @param course Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees.
 * @param heading Compass heading in degrees * 100, 0.0..359.99 degrees (titlt compensated).
 * @param headingNc Compass heading in degrees * 100, 0.0..359.99 degrees (not titlt compensated).
 * @param hdop GPS HDOP horizontal dilution of position in cm (m*100).
 * @param vdop GPS VDOP vertical dilution of position in cm (m*100).
 * @param pitch Pitch in degrees.
 * @param roll Roll in degrees.
 * @param voltageBattery Battery voltage, in millivolts (1 = 1 millivolt).
 * @param currentBattery Battery current, in milliampere (1 = 1 milliampere).
 * @param consumedBattery Battery current consumed, in milliampere (1 = 1 milliampere).
 * @param flightMode 0:manual, 1: GPS, 2: FAILSAFE, 3: ATTI.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dji_system_status_send(mavlink_channel_t chan, int32_t latitude, int32_t longitude, int32_t latitudeHome, int32_t longitudeHome, int32_t altitudeHome, int32_t altitudeBarometer, int32_t altitudeGps, int16_t speed, int16_t climbSpeedBarometer, int16_t climbSpeedGps, uint8_t satellitesVisible, uint8_t fixType, uint16_t course, uint16_t heading, uint16_t headingNc, uint16_t hdop, uint16_t vdop, int8_t pitch, int8_t roll, uint16_t voltageBattery, uint16_t currentBattery, uint16_t consumedBattery, uint8_t flightMode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN];
	_mav_put_int32_t(buf, 0, latitude);
	_mav_put_int32_t(buf, 4, longitude);
	_mav_put_int32_t(buf, 8, latitudeHome);
	_mav_put_int32_t(buf, 12, longitudeHome);
	_mav_put_int32_t(buf, 16, altitudeHome);
	_mav_put_int32_t(buf, 20, altitudeBarometer);
	_mav_put_int32_t(buf, 24, altitudeGps);
	_mav_put_int16_t(buf, 28, speed);
	_mav_put_int16_t(buf, 30, climbSpeedBarometer);
	_mav_put_int16_t(buf, 32, climbSpeedGps);
	_mav_put_uint16_t(buf, 34, course);
	_mav_put_uint16_t(buf, 36, heading);
	_mav_put_uint16_t(buf, 38, headingNc);
	_mav_put_uint16_t(buf, 40, hdop);
	_mav_put_uint16_t(buf, 42, vdop);
	_mav_put_uint16_t(buf, 44, voltageBattery);
	_mav_put_uint16_t(buf, 46, currentBattery);
	_mav_put_uint16_t(buf, 48, consumedBattery);
	_mav_put_uint8_t(buf, 50, satellitesVisible);
	_mav_put_uint8_t(buf, 51, fixType);
	_mav_put_int8_t(buf, 52, pitch);
	_mav_put_int8_t(buf, 53, roll);
	_mav_put_uint8_t(buf, 54, flightMode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS, buf, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS, buf, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN);
#endif
#else
	mavlink_dji_system_status_t packet;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.latitudeHome = latitudeHome;
	packet.longitudeHome = longitudeHome;
	packet.altitudeHome = altitudeHome;
	packet.altitudeBarometer = altitudeBarometer;
	packet.altitudeGps = altitudeGps;
	packet.speed = speed;
	packet.climbSpeedBarometer = climbSpeedBarometer;
	packet.climbSpeedGps = climbSpeedGps;
	packet.course = course;
	packet.heading = heading;
	packet.headingNc = headingNc;
	packet.hdop = hdop;
	packet.vdop = vdop;
	packet.voltageBattery = voltageBattery;
	packet.currentBattery = currentBattery;
	packet.consumedBattery = consumedBattery;
	packet.satellitesVisible = satellitesVisible;
	packet.fixType = fixType;
	packet.pitch = pitch;
	packet.roll = roll;
	packet.flightMode = flightMode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS, (const char *)&packet, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS, (const char *)&packet, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dji_system_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t latitude, int32_t longitude, int32_t latitudeHome, int32_t longitudeHome, int32_t altitudeHome, int32_t altitudeBarometer, int32_t altitudeGps, int16_t speed, int16_t climbSpeedBarometer, int16_t climbSpeedGps, uint8_t satellitesVisible, uint8_t fixType, uint16_t course, uint16_t heading, uint16_t headingNc, uint16_t hdop, uint16_t vdop, int8_t pitch, int8_t roll, uint16_t voltageBattery, uint16_t currentBattery, uint16_t consumedBattery, uint8_t flightMode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, latitude);
	_mav_put_int32_t(buf, 4, longitude);
	_mav_put_int32_t(buf, 8, latitudeHome);
	_mav_put_int32_t(buf, 12, longitudeHome);
	_mav_put_int32_t(buf, 16, altitudeHome);
	_mav_put_int32_t(buf, 20, altitudeBarometer);
	_mav_put_int32_t(buf, 24, altitudeGps);
	_mav_put_int16_t(buf, 28, speed);
	_mav_put_int16_t(buf, 30, climbSpeedBarometer);
	_mav_put_int16_t(buf, 32, climbSpeedGps);
	_mav_put_uint16_t(buf, 34, course);
	_mav_put_uint16_t(buf, 36, heading);
	_mav_put_uint16_t(buf, 38, headingNc);
	_mav_put_uint16_t(buf, 40, hdop);
	_mav_put_uint16_t(buf, 42, vdop);
	_mav_put_uint16_t(buf, 44, voltageBattery);
	_mav_put_uint16_t(buf, 46, currentBattery);
	_mav_put_uint16_t(buf, 48, consumedBattery);
	_mav_put_uint8_t(buf, 50, satellitesVisible);
	_mav_put_uint8_t(buf, 51, fixType);
	_mav_put_int8_t(buf, 52, pitch);
	_mav_put_int8_t(buf, 53, roll);
	_mav_put_uint8_t(buf, 54, flightMode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS, buf, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS, buf, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN);
#endif
#else
	mavlink_dji_system_status_t *packet = (mavlink_dji_system_status_t *)msgbuf;
	packet->latitude = latitude;
	packet->longitude = longitude;
	packet->latitudeHome = latitudeHome;
	packet->longitudeHome = longitudeHome;
	packet->altitudeHome = altitudeHome;
	packet->altitudeBarometer = altitudeBarometer;
	packet->altitudeGps = altitudeGps;
	packet->speed = speed;
	packet->climbSpeedBarometer = climbSpeedBarometer;
	packet->climbSpeedGps = climbSpeedGps;
	packet->course = course;
	packet->heading = heading;
	packet->headingNc = headingNc;
	packet->hdop = hdop;
	packet->vdop = vdop;
	packet->voltageBattery = voltageBattery;
	packet->currentBattery = currentBattery;
	packet->consumedBattery = consumedBattery;
	packet->satellitesVisible = satellitesVisible;
	packet->fixType = fixType;
	packet->pitch = pitch;
	packet->roll = roll;
	packet->flightMode = flightMode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS, (const char *)packet, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS, (const char *)packet, MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE DJI_SYSTEM_STATUS UNPACKING


/**
 * @brief Get field latitude from dji_system_status message
 *
 * @return Latitude (WGS84), in degrees * 1E7.
 */
static inline int32_t mavlink_msg_dji_system_status_get_latitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field longitude from dji_system_status message
 *
 * @return Longitude (WGS84), in degrees * 1E7.
 */
static inline int32_t mavlink_msg_dji_system_status_get_longitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field latitudeHome from dji_system_status message
 *
 * @return Home Latitude (WGS84), in degrees * 1E7.
 */
static inline int32_t mavlink_msg_dji_system_status_get_latitudeHome(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field longitudeHome from dji_system_status message
 *
 * @return Home Longitude (WGS84), in degrees * 1E7.
 */
static inline int32_t mavlink_msg_dji_system_status_get_longitudeHome(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field altitudeHome from dji_system_status message
 *
 * @return home altitude from barometric sensor plus 20m (meters)
 */
static inline int32_t mavlink_msg_dji_system_status_get_altitudeHome(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field altitudeBarometer from dji_system_status message
 *
 * @return Altitude (Barometer), in meters * 1000 (positive for up)
 */
static inline int32_t mavlink_msg_dji_system_status_get_altitudeBarometer(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field altitudeGps from dji_system_status message
 *
 * @return Altitude (WGS84), in meters * 1000 (positive for up).
 */
static inline int32_t mavlink_msg_dji_system_status_get_altitudeGps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field speed from dji_system_status message
 *
 * @return GPS ground speed (m/s * 100).
 */
static inline int16_t mavlink_msg_dji_system_status_get_speed(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field climbSpeedBarometer from dji_system_status message
 *
 * @return Barometer vertical speed (m/s * 100).
 */
static inline int16_t mavlink_msg_dji_system_status_get_climbSpeedBarometer(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field climbSpeedGps from dji_system_status message
 *
 * @return GPS vertical speed (m/s * 100).
 */
static inline int16_t mavlink_msg_dji_system_status_get_climbSpeedGps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  32);
}

/**
 * @brief Get field satellitesVisible from dji_system_status message
 *
 * @return Number of satellites visible. If unknown, set to 255.
 */
static inline uint8_t mavlink_msg_dji_system_status_get_satellitesVisible(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  50);
}

/**
 * @brief Get field fixType from dji_system_status message
 *
 * @return 0-1: no fix, 2: 2D fix, 3: 3D fix, 4: DGPS.
 */
static inline uint8_t mavlink_msg_dji_system_status_get_fixType(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  51);
}

/**
 * @brief Get field course from dji_system_status message
 *
 * @return Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees.
 */
static inline uint16_t mavlink_msg_dji_system_status_get_course(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field heading from dji_system_status message
 *
 * @return Compass heading in degrees * 100, 0.0..359.99 degrees (titlt compensated).
 */
static inline uint16_t mavlink_msg_dji_system_status_get_heading(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  36);
}

/**
 * @brief Get field headingNc from dji_system_status message
 *
 * @return Compass heading in degrees * 100, 0.0..359.99 degrees (not titlt compensated).
 */
static inline uint16_t mavlink_msg_dji_system_status_get_headingNc(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  38);
}

/**
 * @brief Get field hdop from dji_system_status message
 *
 * @return GPS HDOP horizontal dilution of position in cm (m*100).
 */
static inline uint16_t mavlink_msg_dji_system_status_get_hdop(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field vdop from dji_system_status message
 *
 * @return GPS VDOP vertical dilution of position in cm (m*100).
 */
static inline uint16_t mavlink_msg_dji_system_status_get_vdop(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  42);
}

/**
 * @brief Get field pitch from dji_system_status message
 *
 * @return Pitch in degrees.
 */
static inline int8_t mavlink_msg_dji_system_status_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  52);
}

/**
 * @brief Get field roll from dji_system_status message
 *
 * @return Roll in degrees.
 */
static inline int8_t mavlink_msg_dji_system_status_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  53);
}

/**
 * @brief Get field voltageBattery from dji_system_status message
 *
 * @return Battery voltage, in millivolts (1 = 1 millivolt).
 */
static inline uint16_t mavlink_msg_dji_system_status_get_voltageBattery(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  44);
}

/**
 * @brief Get field currentBattery from dji_system_status message
 *
 * @return Battery current, in milliampere (1 = 1 milliampere).
 */
static inline uint16_t mavlink_msg_dji_system_status_get_currentBattery(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  46);
}

/**
 * @brief Get field consumedBattery from dji_system_status message
 *
 * @return Battery current consumed, in milliampere (1 = 1 milliampere).
 */
static inline uint16_t mavlink_msg_dji_system_status_get_consumedBattery(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  48);
}

/**
 * @brief Get field flightMode from dji_system_status message
 *
 * @return 0:manual, 1: GPS, 2: FAILSAFE, 3: ATTI.
 */
static inline uint8_t mavlink_msg_dji_system_status_get_flightMode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  54);
}

/**
 * @brief Decode a dji_system_status message into a struct
 *
 * @param msg The message to decode
 * @param dji_system_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_dji_system_status_decode(const mavlink_message_t* msg, mavlink_dji_system_status_t* dji_system_status)
{
#if MAVLINK_NEED_BYTE_SWAP
	dji_system_status->latitude = mavlink_msg_dji_system_status_get_latitude(msg);
	dji_system_status->longitude = mavlink_msg_dji_system_status_get_longitude(msg);
	dji_system_status->latitudeHome = mavlink_msg_dji_system_status_get_latitudeHome(msg);
	dji_system_status->longitudeHome = mavlink_msg_dji_system_status_get_longitudeHome(msg);
	dji_system_status->altitudeHome = mavlink_msg_dji_system_status_get_altitudeHome(msg);
	dji_system_status->altitudeBarometer = mavlink_msg_dji_system_status_get_altitudeBarometer(msg);
	dji_system_status->altitudeGps = mavlink_msg_dji_system_status_get_altitudeGps(msg);
	dji_system_status->speed = mavlink_msg_dji_system_status_get_speed(msg);
	dji_system_status->climbSpeedBarometer = mavlink_msg_dji_system_status_get_climbSpeedBarometer(msg);
	dji_system_status->climbSpeedGps = mavlink_msg_dji_system_status_get_climbSpeedGps(msg);
	dji_system_status->course = mavlink_msg_dji_system_status_get_course(msg);
	dji_system_status->heading = mavlink_msg_dji_system_status_get_heading(msg);
	dji_system_status->headingNc = mavlink_msg_dji_system_status_get_headingNc(msg);
	dji_system_status->hdop = mavlink_msg_dji_system_status_get_hdop(msg);
	dji_system_status->vdop = mavlink_msg_dji_system_status_get_vdop(msg);
	dji_system_status->voltageBattery = mavlink_msg_dji_system_status_get_voltageBattery(msg);
	dji_system_status->currentBattery = mavlink_msg_dji_system_status_get_currentBattery(msg);
	dji_system_status->consumedBattery = mavlink_msg_dji_system_status_get_consumedBattery(msg);
	dji_system_status->satellitesVisible = mavlink_msg_dji_system_status_get_satellitesVisible(msg);
	dji_system_status->fixType = mavlink_msg_dji_system_status_get_fixType(msg);
	dji_system_status->pitch = mavlink_msg_dji_system_status_get_pitch(msg);
	dji_system_status->roll = mavlink_msg_dji_system_status_get_roll(msg);
	dji_system_status->flightMode = mavlink_msg_dji_system_status_get_flightMode(msg);
#else
	memcpy(dji_system_status, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_DJI_SYSTEM_STATUS_LEN);
#endif
}
