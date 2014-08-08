// MESSAGE WAYPOINT_SET_GLOBAL_REFERENCE PACKING

#define MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE 48

typedef struct __mavlink_waypoint_set_global_reference_t
{
 float global_x; ///< global x position
 float global_y; ///< global y position
 float global_z; ///< global z position
 float global_yaw; ///< global yaw orientation in radians, 0 = NORTH
 float local_x; ///< local x position that matches the global x position
 float local_y; ///< local y position that matches the global y position
 float local_z; ///< local z position that matches the global z position
 float local_yaw; ///< local yaw that matches the global yaw orientation
 uint8_t target_system; ///< System ID
 uint8_t target_component; ///< Component ID
} mavlink_waypoint_set_global_reference_t;

#define MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN 34
#define MAVLINK_MSG_ID_48_LEN 34

#define MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_CRC 154
#define MAVLINK_MSG_ID_48_CRC 154



#define MAVLINK_MESSAGE_INFO_WAYPOINT_SET_GLOBAL_REFERENCE { \
	"WAYPOINT_SET_GLOBAL_REFERENCE", \
	10, \
	{  { "global_x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_waypoint_set_global_reference_t, global_x) }, \
         { "global_y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_waypoint_set_global_reference_t, global_y) }, \
         { "global_z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_waypoint_set_global_reference_t, global_z) }, \
         { "global_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_waypoint_set_global_reference_t, global_yaw) }, \
         { "local_x", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_waypoint_set_global_reference_t, local_x) }, \
         { "local_y", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_waypoint_set_global_reference_t, local_y) }, \
         { "local_z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_waypoint_set_global_reference_t, local_z) }, \
         { "local_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_waypoint_set_global_reference_t, local_yaw) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_waypoint_set_global_reference_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_waypoint_set_global_reference_t, target_component) }, \
         } \
}


/**
 * @brief Pack a waypoint_set_global_reference message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param global_x global x position
 * @param global_y global y position
 * @param global_z global z position
 * @param global_yaw global yaw orientation in radians, 0 = NORTH
 * @param local_x local x position that matches the global x position
 * @param local_y local y position that matches the global y position
 * @param local_z local z position that matches the global z position
 * @param local_yaw local yaw that matches the global yaw orientation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_waypoint_set_global_reference_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, float global_x, float global_y, float global_z, float global_yaw, float local_x, float local_y, float local_z, float local_yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN];
	_mav_put_float(buf, 0, global_x);
	_mav_put_float(buf, 4, global_y);
	_mav_put_float(buf, 8, global_z);
	_mav_put_float(buf, 12, global_yaw);
	_mav_put_float(buf, 16, local_x);
	_mav_put_float(buf, 20, local_y);
	_mav_put_float(buf, 24, local_z);
	_mav_put_float(buf, 28, local_yaw);
	_mav_put_uint8_t(buf, 32, target_system);
	_mav_put_uint8_t(buf, 33, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN);
#else
	mavlink_waypoint_set_global_reference_t packet;
	packet.global_x = global_x;
	packet.global_y = global_y;
	packet.global_z = global_z;
	packet.global_yaw = global_yaw;
	packet.local_x = local_x;
	packet.local_y = local_y;
	packet.local_z = local_z;
	packet.local_yaw = local_yaw;
	packet.target_system = target_system;
	packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN);
#endif
}

/**
 * @brief Pack a waypoint_set_global_reference message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param global_x global x position
 * @param global_y global y position
 * @param global_z global z position
 * @param global_yaw global yaw orientation in radians, 0 = NORTH
 * @param local_x local x position that matches the global x position
 * @param local_y local y position that matches the global y position
 * @param local_z local z position that matches the global z position
 * @param local_yaw local yaw that matches the global yaw orientation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_waypoint_set_global_reference_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,float global_x,float global_y,float global_z,float global_yaw,float local_x,float local_y,float local_z,float local_yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN];
	_mav_put_float(buf, 0, global_x);
	_mav_put_float(buf, 4, global_y);
	_mav_put_float(buf, 8, global_z);
	_mav_put_float(buf, 12, global_yaw);
	_mav_put_float(buf, 16, local_x);
	_mav_put_float(buf, 20, local_y);
	_mav_put_float(buf, 24, local_z);
	_mav_put_float(buf, 28, local_yaw);
	_mav_put_uint8_t(buf, 32, target_system);
	_mav_put_uint8_t(buf, 33, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN);
#else
	mavlink_waypoint_set_global_reference_t packet;
	packet.global_x = global_x;
	packet.global_y = global_y;
	packet.global_z = global_z;
	packet.global_yaw = global_yaw;
	packet.local_x = local_x;
	packet.local_y = local_y;
	packet.local_z = local_z;
	packet.local_yaw = local_yaw;
	packet.target_system = target_system;
	packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN);
#endif
}

/**
 * @brief Encode a waypoint_set_global_reference struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param waypoint_set_global_reference C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_waypoint_set_global_reference_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_waypoint_set_global_reference_t* waypoint_set_global_reference)
{
	return mavlink_msg_waypoint_set_global_reference_pack(system_id, component_id, msg, waypoint_set_global_reference->target_system, waypoint_set_global_reference->target_component, waypoint_set_global_reference->global_x, waypoint_set_global_reference->global_y, waypoint_set_global_reference->global_z, waypoint_set_global_reference->global_yaw, waypoint_set_global_reference->local_x, waypoint_set_global_reference->local_y, waypoint_set_global_reference->local_z, waypoint_set_global_reference->local_yaw);
}

/**
 * @brief Encode a waypoint_set_global_reference struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param waypoint_set_global_reference C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_waypoint_set_global_reference_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_waypoint_set_global_reference_t* waypoint_set_global_reference)
{
	return mavlink_msg_waypoint_set_global_reference_pack_chan(system_id, component_id, chan, msg, waypoint_set_global_reference->target_system, waypoint_set_global_reference->target_component, waypoint_set_global_reference->global_x, waypoint_set_global_reference->global_y, waypoint_set_global_reference->global_z, waypoint_set_global_reference->global_yaw, waypoint_set_global_reference->local_x, waypoint_set_global_reference->local_y, waypoint_set_global_reference->local_z, waypoint_set_global_reference->local_yaw);
}

/**
 * @brief Send a waypoint_set_global_reference message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param global_x global x position
 * @param global_y global y position
 * @param global_z global z position
 * @param global_yaw global yaw orientation in radians, 0 = NORTH
 * @param local_x local x position that matches the global x position
 * @param local_y local y position that matches the global y position
 * @param local_z local z position that matches the global z position
 * @param local_yaw local yaw that matches the global yaw orientation
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_waypoint_set_global_reference_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, float global_x, float global_y, float global_z, float global_yaw, float local_x, float local_y, float local_z, float local_yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN];
	_mav_put_float(buf, 0, global_x);
	_mav_put_float(buf, 4, global_y);
	_mav_put_float(buf, 8, global_z);
	_mav_put_float(buf, 12, global_yaw);
	_mav_put_float(buf, 16, local_x);
	_mav_put_float(buf, 20, local_y);
	_mav_put_float(buf, 24, local_z);
	_mav_put_float(buf, 28, local_yaw);
	_mav_put_uint8_t(buf, 32, target_system);
	_mav_put_uint8_t(buf, 33, target_component);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE, buf, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE, buf, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN);
#endif
#else
	mavlink_waypoint_set_global_reference_t packet;
	packet.global_x = global_x;
	packet.global_y = global_y;
	packet.global_z = global_z;
	packet.global_yaw = global_yaw;
	packet.local_x = local_x;
	packet.local_y = local_y;
	packet.local_z = local_z;
	packet.local_yaw = local_yaw;
	packet.target_system = target_system;
	packet.target_component = target_component;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE, (const char *)&packet, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE, (const char *)&packet, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_waypoint_set_global_reference_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, float global_x, float global_y, float global_z, float global_yaw, float local_x, float local_y, float local_z, float local_yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, global_x);
	_mav_put_float(buf, 4, global_y);
	_mav_put_float(buf, 8, global_z);
	_mav_put_float(buf, 12, global_yaw);
	_mav_put_float(buf, 16, local_x);
	_mav_put_float(buf, 20, local_y);
	_mav_put_float(buf, 24, local_z);
	_mav_put_float(buf, 28, local_yaw);
	_mav_put_uint8_t(buf, 32, target_system);
	_mav_put_uint8_t(buf, 33, target_component);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE, buf, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE, buf, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN);
#endif
#else
	mavlink_waypoint_set_global_reference_t *packet = (mavlink_waypoint_set_global_reference_t *)msgbuf;
	packet->global_x = global_x;
	packet->global_y = global_y;
	packet->global_z = global_z;
	packet->global_yaw = global_yaw;
	packet->local_x = local_x;
	packet->local_y = local_y;
	packet->local_z = local_z;
	packet->local_yaw = local_yaw;
	packet->target_system = target_system;
	packet->target_component = target_component;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE, (const char *)packet, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE, (const char *)packet, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE WAYPOINT_SET_GLOBAL_REFERENCE UNPACKING


/**
 * @brief Get field target_system from waypoint_set_global_reference message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_waypoint_set_global_reference_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field target_component from waypoint_set_global_reference message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_waypoint_set_global_reference_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  33);
}

/**
 * @brief Get field global_x from waypoint_set_global_reference message
 *
 * @return global x position
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_global_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field global_y from waypoint_set_global_reference message
 *
 * @return global y position
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_global_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field global_z from waypoint_set_global_reference message
 *
 * @return global z position
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_global_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field global_yaw from waypoint_set_global_reference message
 *
 * @return global yaw orientation in radians, 0 = NORTH
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_global_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field local_x from waypoint_set_global_reference message
 *
 * @return local x position that matches the global x position
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_local_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field local_y from waypoint_set_global_reference message
 *
 * @return local y position that matches the global y position
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_local_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field local_z from waypoint_set_global_reference message
 *
 * @return local z position that matches the global z position
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_local_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field local_yaw from waypoint_set_global_reference message
 *
 * @return local yaw that matches the global yaw orientation
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_local_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Decode a waypoint_set_global_reference message into a struct
 *
 * @param msg The message to decode
 * @param waypoint_set_global_reference C-struct to decode the message contents into
 */
static inline void mavlink_msg_waypoint_set_global_reference_decode(const mavlink_message_t* msg, mavlink_waypoint_set_global_reference_t* waypoint_set_global_reference)
{
#if MAVLINK_NEED_BYTE_SWAP
	waypoint_set_global_reference->global_x = mavlink_msg_waypoint_set_global_reference_get_global_x(msg);
	waypoint_set_global_reference->global_y = mavlink_msg_waypoint_set_global_reference_get_global_y(msg);
	waypoint_set_global_reference->global_z = mavlink_msg_waypoint_set_global_reference_get_global_z(msg);
	waypoint_set_global_reference->global_yaw = mavlink_msg_waypoint_set_global_reference_get_global_yaw(msg);
	waypoint_set_global_reference->local_x = mavlink_msg_waypoint_set_global_reference_get_local_x(msg);
	waypoint_set_global_reference->local_y = mavlink_msg_waypoint_set_global_reference_get_local_y(msg);
	waypoint_set_global_reference->local_z = mavlink_msg_waypoint_set_global_reference_get_local_z(msg);
	waypoint_set_global_reference->local_yaw = mavlink_msg_waypoint_set_global_reference_get_local_yaw(msg);
	waypoint_set_global_reference->target_system = mavlink_msg_waypoint_set_global_reference_get_target_system(msg);
	waypoint_set_global_reference->target_component = mavlink_msg_waypoint_set_global_reference_get_target_component(msg);
#else
	memcpy(waypoint_set_global_reference, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN);
#endif
}
