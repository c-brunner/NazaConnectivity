// MESSAGE POSITION_CONTROLLER_OUTPUT PACKING

#define MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT 61

typedef struct __mavlink_position_controller_output_t
{
 uint8_t enabled; ///< 1: enabled, 0: disabled
 int8_t x; ///< Position x: -128: -100%, 127: +100%
 int8_t y; ///< Position y: -128: -100%, 127: +100%
 int8_t z; ///< Position z: -128: -100%, 127: +100%
 int8_t yaw; ///< Position yaw: -128: -100%, 127: +100%
} mavlink_position_controller_output_t;

#define MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN 5
#define MAVLINK_MSG_ID_61_LEN 5

#define MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_CRC 179
#define MAVLINK_MSG_ID_61_CRC 179



#define MAVLINK_MESSAGE_INFO_POSITION_CONTROLLER_OUTPUT { \
	"POSITION_CONTROLLER_OUTPUT", \
	5, \
	{  { "enabled", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_position_controller_output_t, enabled) }, \
         { "x", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_position_controller_output_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT8_T, 0, 2, offsetof(mavlink_position_controller_output_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT8_T, 0, 3, offsetof(mavlink_position_controller_output_t, z) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT8_T, 0, 4, offsetof(mavlink_position_controller_output_t, yaw) }, \
         } \
}


/**
 * @brief Pack a position_controller_output message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param enabled 1: enabled, 0: disabled
 * @param x Position x: -128: -100%, 127: +100%
 * @param y Position y: -128: -100%, 127: +100%
 * @param z Position z: -128: -100%, 127: +100%
 * @param yaw Position yaw: -128: -100%, 127: +100%
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_controller_output_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t enabled, int8_t x, int8_t y, int8_t z, int8_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN];
	_mav_put_uint8_t(buf, 0, enabled);
	_mav_put_int8_t(buf, 1, x);
	_mav_put_int8_t(buf, 2, y);
	_mav_put_int8_t(buf, 3, z);
	_mav_put_int8_t(buf, 4, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN);
#else
	mavlink_position_controller_output_t packet;
	packet.enabled = enabled;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN);
#endif
}

/**
 * @brief Pack a position_controller_output message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param enabled 1: enabled, 0: disabled
 * @param x Position x: -128: -100%, 127: +100%
 * @param y Position y: -128: -100%, 127: +100%
 * @param z Position z: -128: -100%, 127: +100%
 * @param yaw Position yaw: -128: -100%, 127: +100%
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_controller_output_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t enabled,int8_t x,int8_t y,int8_t z,int8_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN];
	_mav_put_uint8_t(buf, 0, enabled);
	_mav_put_int8_t(buf, 1, x);
	_mav_put_int8_t(buf, 2, y);
	_mav_put_int8_t(buf, 3, z);
	_mav_put_int8_t(buf, 4, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN);
#else
	mavlink_position_controller_output_t packet;
	packet.enabled = enabled;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN);
#endif
}

/**
 * @brief Encode a position_controller_output struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param position_controller_output C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_controller_output_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_position_controller_output_t* position_controller_output)
{
	return mavlink_msg_position_controller_output_pack(system_id, component_id, msg, position_controller_output->enabled, position_controller_output->x, position_controller_output->y, position_controller_output->z, position_controller_output->yaw);
}

/**
 * @brief Encode a position_controller_output struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param position_controller_output C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_controller_output_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_position_controller_output_t* position_controller_output)
{
	return mavlink_msg_position_controller_output_pack_chan(system_id, component_id, chan, msg, position_controller_output->enabled, position_controller_output->x, position_controller_output->y, position_controller_output->z, position_controller_output->yaw);
}

/**
 * @brief Send a position_controller_output message
 * @param chan MAVLink channel to send the message
 *
 * @param enabled 1: enabled, 0: disabled
 * @param x Position x: -128: -100%, 127: +100%
 * @param y Position y: -128: -100%, 127: +100%
 * @param z Position z: -128: -100%, 127: +100%
 * @param yaw Position yaw: -128: -100%, 127: +100%
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_position_controller_output_send(mavlink_channel_t chan, uint8_t enabled, int8_t x, int8_t y, int8_t z, int8_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN];
	_mav_put_uint8_t(buf, 0, enabled);
	_mav_put_int8_t(buf, 1, x);
	_mav_put_int8_t(buf, 2, y);
	_mav_put_int8_t(buf, 3, z);
	_mav_put_int8_t(buf, 4, yaw);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT, buf, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT, buf, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN);
#endif
#else
	mavlink_position_controller_output_t packet;
	packet.enabled = enabled;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.yaw = yaw;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT, (const char *)&packet, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT, (const char *)&packet, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_position_controller_output_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t enabled, int8_t x, int8_t y, int8_t z, int8_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, enabled);
	_mav_put_int8_t(buf, 1, x);
	_mav_put_int8_t(buf, 2, y);
	_mav_put_int8_t(buf, 3, z);
	_mav_put_int8_t(buf, 4, yaw);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT, buf, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT, buf, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN);
#endif
#else
	mavlink_position_controller_output_t *packet = (mavlink_position_controller_output_t *)msgbuf;
	packet->enabled = enabled;
	packet->x = x;
	packet->y = y;
	packet->z = z;
	packet->yaw = yaw;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT, (const char *)packet, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT, (const char *)packet, MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE POSITION_CONTROLLER_OUTPUT UNPACKING


/**
 * @brief Get field enabled from position_controller_output message
 *
 * @return 1: enabled, 0: disabled
 */
static inline uint8_t mavlink_msg_position_controller_output_get_enabled(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field x from position_controller_output message
 *
 * @return Position x: -128: -100%, 127: +100%
 */
static inline int8_t mavlink_msg_position_controller_output_get_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  1);
}

/**
 * @brief Get field y from position_controller_output message
 *
 * @return Position y: -128: -100%, 127: +100%
 */
static inline int8_t mavlink_msg_position_controller_output_get_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  2);
}

/**
 * @brief Get field z from position_controller_output message
 *
 * @return Position z: -128: -100%, 127: +100%
 */
static inline int8_t mavlink_msg_position_controller_output_get_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  3);
}

/**
 * @brief Get field yaw from position_controller_output message
 *
 * @return Position yaw: -128: -100%, 127: +100%
 */
static inline int8_t mavlink_msg_position_controller_output_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  4);
}

/**
 * @brief Decode a position_controller_output message into a struct
 *
 * @param msg The message to decode
 * @param position_controller_output C-struct to decode the message contents into
 */
static inline void mavlink_msg_position_controller_output_decode(const mavlink_message_t* msg, mavlink_position_controller_output_t* position_controller_output)
{
#if MAVLINK_NEED_BYTE_SWAP
	position_controller_output->enabled = mavlink_msg_position_controller_output_get_enabled(msg);
	position_controller_output->x = mavlink_msg_position_controller_output_get_x(msg);
	position_controller_output->y = mavlink_msg_position_controller_output_get_y(msg);
	position_controller_output->z = mavlink_msg_position_controller_output_get_z(msg);
	position_controller_output->yaw = mavlink_msg_position_controller_output_get_yaw(msg);
#else
	memcpy(position_controller_output, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_POSITION_CONTROLLER_OUTPUT_LEN);
#endif
}
