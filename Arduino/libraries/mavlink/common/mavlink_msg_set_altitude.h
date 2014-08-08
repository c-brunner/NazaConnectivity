// MESSAGE SET_ALTITUDE PACKING

#define MAVLINK_MSG_ID_SET_ALTITUDE 65

typedef struct __mavlink_set_altitude_t
{
 uint32_t mode; ///< The new altitude in meters
 uint8_t target; ///< The system setting the altitude
} mavlink_set_altitude_t;

#define MAVLINK_MSG_ID_SET_ALTITUDE_LEN 5
#define MAVLINK_MSG_ID_65_LEN 5

#define MAVLINK_MSG_ID_SET_ALTITUDE_CRC 54
#define MAVLINK_MSG_ID_65_CRC 54



#define MAVLINK_MESSAGE_INFO_SET_ALTITUDE { \
	"SET_ALTITUDE", \
	2, \
	{  { "mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_altitude_t, mode) }, \
         { "target", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_set_altitude_t, target) }, \
         } \
}


/**
 * @brief Pack a set_altitude message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target The system setting the altitude
 * @param mode The new altitude in meters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_altitude_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target, uint32_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SET_ALTITUDE_LEN];
	_mav_put_uint32_t(buf, 0, mode);
	_mav_put_uint8_t(buf, 4, target);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_ALTITUDE_LEN);
#else
	mavlink_set_altitude_t packet;
	packet.mode = mode;
	packet.target = target;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_ALTITUDE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SET_ALTITUDE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_ALTITUDE_LEN, MAVLINK_MSG_ID_SET_ALTITUDE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_ALTITUDE_LEN);
#endif
}

/**
 * @brief Pack a set_altitude message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target The system setting the altitude
 * @param mode The new altitude in meters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_altitude_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target,uint32_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SET_ALTITUDE_LEN];
	_mav_put_uint32_t(buf, 0, mode);
	_mav_put_uint8_t(buf, 4, target);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_ALTITUDE_LEN);
#else
	mavlink_set_altitude_t packet;
	packet.mode = mode;
	packet.target = target;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_ALTITUDE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SET_ALTITUDE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_ALTITUDE_LEN, MAVLINK_MSG_ID_SET_ALTITUDE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_ALTITUDE_LEN);
#endif
}

/**
 * @brief Encode a set_altitude struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_altitude C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_altitude_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_altitude_t* set_altitude)
{
	return mavlink_msg_set_altitude_pack(system_id, component_id, msg, set_altitude->target, set_altitude->mode);
}

/**
 * @brief Encode a set_altitude struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_altitude C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_altitude_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_altitude_t* set_altitude)
{
	return mavlink_msg_set_altitude_pack_chan(system_id, component_id, chan, msg, set_altitude->target, set_altitude->mode);
}

/**
 * @brief Send a set_altitude message
 * @param chan MAVLink channel to send the message
 *
 * @param target The system setting the altitude
 * @param mode The new altitude in meters
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_altitude_send(mavlink_channel_t chan, uint8_t target, uint32_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SET_ALTITUDE_LEN];
	_mav_put_uint32_t(buf, 0, mode);
	_mav_put_uint8_t(buf, 4, target);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ALTITUDE, buf, MAVLINK_MSG_ID_SET_ALTITUDE_LEN, MAVLINK_MSG_ID_SET_ALTITUDE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ALTITUDE, buf, MAVLINK_MSG_ID_SET_ALTITUDE_LEN);
#endif
#else
	mavlink_set_altitude_t packet;
	packet.mode = mode;
	packet.target = target;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ALTITUDE, (const char *)&packet, MAVLINK_MSG_ID_SET_ALTITUDE_LEN, MAVLINK_MSG_ID_SET_ALTITUDE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ALTITUDE, (const char *)&packet, MAVLINK_MSG_ID_SET_ALTITUDE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SET_ALTITUDE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_altitude_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target, uint32_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, mode);
	_mav_put_uint8_t(buf, 4, target);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ALTITUDE, buf, MAVLINK_MSG_ID_SET_ALTITUDE_LEN, MAVLINK_MSG_ID_SET_ALTITUDE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ALTITUDE, buf, MAVLINK_MSG_ID_SET_ALTITUDE_LEN);
#endif
#else
	mavlink_set_altitude_t *packet = (mavlink_set_altitude_t *)msgbuf;
	packet->mode = mode;
	packet->target = target;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ALTITUDE, (const char *)packet, MAVLINK_MSG_ID_SET_ALTITUDE_LEN, MAVLINK_MSG_ID_SET_ALTITUDE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ALTITUDE, (const char *)packet, MAVLINK_MSG_ID_SET_ALTITUDE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SET_ALTITUDE UNPACKING


/**
 * @brief Get field target from set_altitude message
 *
 * @return The system setting the altitude
 */
static inline uint8_t mavlink_msg_set_altitude_get_target(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field mode from set_altitude message
 *
 * @return The new altitude in meters
 */
static inline uint32_t mavlink_msg_set_altitude_get_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a set_altitude message into a struct
 *
 * @param msg The message to decode
 * @param set_altitude C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_altitude_decode(const mavlink_message_t* msg, mavlink_set_altitude_t* set_altitude)
{
#if MAVLINK_NEED_BYTE_SWAP
	set_altitude->mode = mavlink_msg_set_altitude_get_mode(msg);
	set_altitude->target = mavlink_msg_set_altitude_get_target(msg);
#else
	memcpy(set_altitude, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SET_ALTITUDE_LEN);
#endif
}
