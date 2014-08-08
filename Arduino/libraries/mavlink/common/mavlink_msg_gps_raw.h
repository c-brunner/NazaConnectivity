// MESSAGE GPS_RAW PACKING

#define MAVLINK_MSG_ID_GPS_RAW 32

typedef struct __mavlink_gps_raw_t
{
 uint64_t usec; ///< Timestamp (microseconds since unix epoch)
 float lat; ///< X Position
 float lon; ///< Y Position
 float alt; ///< Z Position in meters
 float eph; ///< Uncertainty in meters of latitude
 float epv; ///< Uncertainty in meters of longitude
 float v; ///< Overall speed
 float hdg; ///< Heading, in FIXME
 uint8_t fix_type; ///< 0-1: no fix, 2: 2D fix, 3: 3D fix
} mavlink_gps_raw_t;

#define MAVLINK_MSG_ID_GPS_RAW_LEN 37
#define MAVLINK_MSG_ID_32_LEN 37

#define MAVLINK_MSG_ID_GPS_RAW_CRC 220
#define MAVLINK_MSG_ID_32_CRC 220



#define MAVLINK_MESSAGE_INFO_GPS_RAW { \
	"GPS_RAW", \
	9, \
	{  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_raw_t, usec) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gps_raw_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_gps_raw_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_gps_raw_t, alt) }, \
         { "eph", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_gps_raw_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_gps_raw_t, epv) }, \
         { "v", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_gps_raw_t, v) }, \
         { "hdg", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_gps_raw_t, hdg) }, \
         { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_gps_raw_t, fix_type) }, \
         } \
}


/**
 * @brief Pack a gps_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec Timestamp (microseconds since unix epoch)
 * @param fix_type 0-1: no fix, 2: 2D fix, 3: 3D fix
 * @param lat X Position
 * @param lon Y Position
 * @param alt Z Position in meters
 * @param eph Uncertainty in meters of latitude
 * @param epv Uncertainty in meters of longitude
 * @param v Overall speed
 * @param hdg Heading, in FIXME
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t usec, uint8_t fix_type, float lat, float lon, float alt, float eph, float epv, float v, float hdg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_RAW_LEN];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_float(buf, 8, lat);
	_mav_put_float(buf, 12, lon);
	_mav_put_float(buf, 16, alt);
	_mav_put_float(buf, 20, eph);
	_mav_put_float(buf, 24, epv);
	_mav_put_float(buf, 28, v);
	_mav_put_float(buf, 32, hdg);
	_mav_put_uint8_t(buf, 36, fix_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_RAW_LEN);
#else
	mavlink_gps_raw_t packet;
	packet.usec = usec;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.eph = eph;
	packet.epv = epv;
	packet.v = v;
	packet.hdg = hdg;
	packet.fix_type = fix_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_RAW_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS_RAW;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS_RAW_LEN, MAVLINK_MSG_ID_GPS_RAW_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS_RAW_LEN);
#endif
}

/**
 * @brief Pack a gps_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec Timestamp (microseconds since unix epoch)
 * @param fix_type 0-1: no fix, 2: 2D fix, 3: 3D fix
 * @param lat X Position
 * @param lon Y Position
 * @param alt Z Position in meters
 * @param eph Uncertainty in meters of latitude
 * @param epv Uncertainty in meters of longitude
 * @param v Overall speed
 * @param hdg Heading, in FIXME
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t usec,uint8_t fix_type,float lat,float lon,float alt,float eph,float epv,float v,float hdg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_RAW_LEN];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_float(buf, 8, lat);
	_mav_put_float(buf, 12, lon);
	_mav_put_float(buf, 16, alt);
	_mav_put_float(buf, 20, eph);
	_mav_put_float(buf, 24, epv);
	_mav_put_float(buf, 28, v);
	_mav_put_float(buf, 32, hdg);
	_mav_put_uint8_t(buf, 36, fix_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_RAW_LEN);
#else
	mavlink_gps_raw_t packet;
	packet.usec = usec;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.eph = eph;
	packet.epv = epv;
	packet.v = v;
	packet.hdg = hdg;
	packet.fix_type = fix_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_RAW_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS_RAW;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS_RAW_LEN, MAVLINK_MSG_ID_GPS_RAW_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS_RAW_LEN);
#endif
}

/**
 * @brief Encode a gps_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gps_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_raw_t* gps_raw)
{
	return mavlink_msg_gps_raw_pack(system_id, component_id, msg, gps_raw->usec, gps_raw->fix_type, gps_raw->lat, gps_raw->lon, gps_raw->alt, gps_raw->eph, gps_raw->epv, gps_raw->v, gps_raw->hdg);
}

/**
 * @brief Encode a gps_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gps_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gps_raw_t* gps_raw)
{
	return mavlink_msg_gps_raw_pack_chan(system_id, component_id, chan, msg, gps_raw->usec, gps_raw->fix_type, gps_raw->lat, gps_raw->lon, gps_raw->alt, gps_raw->eph, gps_raw->epv, gps_raw->v, gps_raw->hdg);
}

/**
 * @brief Send a gps_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param usec Timestamp (microseconds since unix epoch)
 * @param fix_type 0-1: no fix, 2: 2D fix, 3: 3D fix
 * @param lat X Position
 * @param lon Y Position
 * @param alt Z Position in meters
 * @param eph Uncertainty in meters of latitude
 * @param epv Uncertainty in meters of longitude
 * @param v Overall speed
 * @param hdg Heading, in FIXME
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gps_raw_send(mavlink_channel_t chan, uint64_t usec, uint8_t fix_type, float lat, float lon, float alt, float eph, float epv, float v, float hdg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_RAW_LEN];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_float(buf, 8, lat);
	_mav_put_float(buf, 12, lon);
	_mav_put_float(buf, 16, alt);
	_mav_put_float(buf, 20, eph);
	_mav_put_float(buf, 24, epv);
	_mav_put_float(buf, 28, v);
	_mav_put_float(buf, 32, hdg);
	_mav_put_uint8_t(buf, 36, fix_type);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RAW, buf, MAVLINK_MSG_ID_GPS_RAW_LEN, MAVLINK_MSG_ID_GPS_RAW_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RAW, buf, MAVLINK_MSG_ID_GPS_RAW_LEN);
#endif
#else
	mavlink_gps_raw_t packet;
	packet.usec = usec;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.eph = eph;
	packet.epv = epv;
	packet.v = v;
	packet.hdg = hdg;
	packet.fix_type = fix_type;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RAW, (const char *)&packet, MAVLINK_MSG_ID_GPS_RAW_LEN, MAVLINK_MSG_ID_GPS_RAW_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RAW, (const char *)&packet, MAVLINK_MSG_ID_GPS_RAW_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_GPS_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gps_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t usec, uint8_t fix_type, float lat, float lon, float alt, float eph, float epv, float v, float hdg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_float(buf, 8, lat);
	_mav_put_float(buf, 12, lon);
	_mav_put_float(buf, 16, alt);
	_mav_put_float(buf, 20, eph);
	_mav_put_float(buf, 24, epv);
	_mav_put_float(buf, 28, v);
	_mav_put_float(buf, 32, hdg);
	_mav_put_uint8_t(buf, 36, fix_type);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RAW, buf, MAVLINK_MSG_ID_GPS_RAW_LEN, MAVLINK_MSG_ID_GPS_RAW_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RAW, buf, MAVLINK_MSG_ID_GPS_RAW_LEN);
#endif
#else
	mavlink_gps_raw_t *packet = (mavlink_gps_raw_t *)msgbuf;
	packet->usec = usec;
	packet->lat = lat;
	packet->lon = lon;
	packet->alt = alt;
	packet->eph = eph;
	packet->epv = epv;
	packet->v = v;
	packet->hdg = hdg;
	packet->fix_type = fix_type;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RAW, (const char *)packet, MAVLINK_MSG_ID_GPS_RAW_LEN, MAVLINK_MSG_ID_GPS_RAW_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RAW, (const char *)packet, MAVLINK_MSG_ID_GPS_RAW_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE GPS_RAW UNPACKING


/**
 * @brief Get field usec from gps_raw message
 *
 * @return Timestamp (microseconds since unix epoch)
 */
static inline uint64_t mavlink_msg_gps_raw_get_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field fix_type from gps_raw message
 *
 * @return 0-1: no fix, 2: 2D fix, 3: 3D fix
 */
static inline uint8_t mavlink_msg_gps_raw_get_fix_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field lat from gps_raw message
 *
 * @return X Position
 */
static inline float mavlink_msg_gps_raw_get_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field lon from gps_raw message
 *
 * @return Y Position
 */
static inline float mavlink_msg_gps_raw_get_lon(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field alt from gps_raw message
 *
 * @return Z Position in meters
 */
static inline float mavlink_msg_gps_raw_get_alt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field eph from gps_raw message
 *
 * @return Uncertainty in meters of latitude
 */
static inline float mavlink_msg_gps_raw_get_eph(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field epv from gps_raw message
 *
 * @return Uncertainty in meters of longitude
 */
static inline float mavlink_msg_gps_raw_get_epv(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field v from gps_raw message
 *
 * @return Overall speed
 */
static inline float mavlink_msg_gps_raw_get_v(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field hdg from gps_raw message
 *
 * @return Heading, in FIXME
 */
static inline float mavlink_msg_gps_raw_get_hdg(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Decode a gps_raw message into a struct
 *
 * @param msg The message to decode
 * @param gps_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_gps_raw_decode(const mavlink_message_t* msg, mavlink_gps_raw_t* gps_raw)
{
#if MAVLINK_NEED_BYTE_SWAP
	gps_raw->usec = mavlink_msg_gps_raw_get_usec(msg);
	gps_raw->lat = mavlink_msg_gps_raw_get_lat(msg);
	gps_raw->lon = mavlink_msg_gps_raw_get_lon(msg);
	gps_raw->alt = mavlink_msg_gps_raw_get_alt(msg);
	gps_raw->eph = mavlink_msg_gps_raw_get_eph(msg);
	gps_raw->epv = mavlink_msg_gps_raw_get_epv(msg);
	gps_raw->v = mavlink_msg_gps_raw_get_v(msg);
	gps_raw->hdg = mavlink_msg_gps_raw_get_hdg(msg);
	gps_raw->fix_type = mavlink_msg_gps_raw_get_fix_type(msg);
#else
	memcpy(gps_raw, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_GPS_RAW_LEN);
#endif
}
