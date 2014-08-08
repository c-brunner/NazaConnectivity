// MESSAGE WAYPOINT PACKING

#define MAVLINK_MSG_ID_WAYPOINT 39

typedef struct __mavlink_waypoint_t
{
 float orbit; ///< Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
 float param1; ///< For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
 float param2; ///< For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
 float x; ///< local: x position, global: longitude
 float y; ///< y position: global: latitude
 float z; ///< z position: global: altitude
 float yaw; ///< yaw orientation in radians, 0 = NORTH
 uint16_t seq; ///< Sequence
 uint8_t target_system; ///< System ID
 uint8_t target_component; ///< Component ID
 uint8_t frame; ///< The coordinate system of the waypoint. see MAV_FRAME in mavlink_types.h
 uint8_t action; ///< The scheduled action for the waypoint. see MAV_ACTION in mavlink_types.h
 uint8_t orbit_direction; ///< Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
 uint8_t current; ///< false:0, true:1
 uint8_t autocontinue; ///< autocontinue to next wp
} mavlink_waypoint_t;

#define MAVLINK_MSG_ID_WAYPOINT_LEN 37
#define MAVLINK_MSG_ID_39_LEN 37

#define MAVLINK_MSG_ID_WAYPOINT_CRC 135
#define MAVLINK_MSG_ID_39_CRC 135



#define MAVLINK_MESSAGE_INFO_WAYPOINT { \
	"WAYPOINT", \
	15, \
	{  { "orbit", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_waypoint_t, orbit) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_waypoint_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_waypoint_t, param2) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_waypoint_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_waypoint_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_waypoint_t, z) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_waypoint_t, yaw) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_waypoint_t, seq) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_waypoint_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_waypoint_t, target_component) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_waypoint_t, frame) }, \
         { "action", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_waypoint_t, action) }, \
         { "orbit_direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_waypoint_t, orbit_direction) }, \
         { "current", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_waypoint_t, current) }, \
         { "autocontinue", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_waypoint_t, autocontinue) }, \
         } \
}


/**
 * @brief Pack a waypoint message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param seq Sequence
 * @param frame The coordinate system of the waypoint. see MAV_FRAME in mavlink_types.h
 * @param action The scheduled action for the waypoint. see MAV_ACTION in mavlink_types.h
 * @param orbit Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
 * @param orbit_direction Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
 * @param param1 For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
 * @param param2 For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
 * @param current false:0, true:1
 * @param x local: x position, global: longitude
 * @param y y position: global: latitude
 * @param z z position: global: altitude
 * @param yaw yaw orientation in radians, 0 = NORTH
 * @param autocontinue autocontinue to next wp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_waypoint_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t frame, uint8_t action, float orbit, uint8_t orbit_direction, float param1, float param2, uint8_t current, float x, float y, float z, float yaw, uint8_t autocontinue)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_WAYPOINT_LEN];
	_mav_put_float(buf, 0, orbit);
	_mav_put_float(buf, 4, param1);
	_mav_put_float(buf, 8, param2);
	_mav_put_float(buf, 12, x);
	_mav_put_float(buf, 16, y);
	_mav_put_float(buf, 20, z);
	_mav_put_float(buf, 24, yaw);
	_mav_put_uint16_t(buf, 28, seq);
	_mav_put_uint8_t(buf, 30, target_system);
	_mav_put_uint8_t(buf, 31, target_component);
	_mav_put_uint8_t(buf, 32, frame);
	_mav_put_uint8_t(buf, 33, action);
	_mav_put_uint8_t(buf, 34, orbit_direction);
	_mav_put_uint8_t(buf, 35, current);
	_mav_put_uint8_t(buf, 36, autocontinue);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WAYPOINT_LEN);
#else
	mavlink_waypoint_t packet;
	packet.orbit = orbit;
	packet.param1 = param1;
	packet.param2 = param2;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.yaw = yaw;
	packet.seq = seq;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.frame = frame;
	packet.action = action;
	packet.orbit_direction = orbit_direction;
	packet.current = current;
	packet.autocontinue = autocontinue;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WAYPOINT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_WAYPOINT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WAYPOINT_LEN, MAVLINK_MSG_ID_WAYPOINT_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WAYPOINT_LEN);
#endif
}

/**
 * @brief Pack a waypoint message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param seq Sequence
 * @param frame The coordinate system of the waypoint. see MAV_FRAME in mavlink_types.h
 * @param action The scheduled action for the waypoint. see MAV_ACTION in mavlink_types.h
 * @param orbit Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
 * @param orbit_direction Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
 * @param param1 For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
 * @param param2 For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
 * @param current false:0, true:1
 * @param x local: x position, global: longitude
 * @param y y position: global: latitude
 * @param z z position: global: altitude
 * @param yaw yaw orientation in radians, 0 = NORTH
 * @param autocontinue autocontinue to next wp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_waypoint_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint16_t seq,uint8_t frame,uint8_t action,float orbit,uint8_t orbit_direction,float param1,float param2,uint8_t current,float x,float y,float z,float yaw,uint8_t autocontinue)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_WAYPOINT_LEN];
	_mav_put_float(buf, 0, orbit);
	_mav_put_float(buf, 4, param1);
	_mav_put_float(buf, 8, param2);
	_mav_put_float(buf, 12, x);
	_mav_put_float(buf, 16, y);
	_mav_put_float(buf, 20, z);
	_mav_put_float(buf, 24, yaw);
	_mav_put_uint16_t(buf, 28, seq);
	_mav_put_uint8_t(buf, 30, target_system);
	_mav_put_uint8_t(buf, 31, target_component);
	_mav_put_uint8_t(buf, 32, frame);
	_mav_put_uint8_t(buf, 33, action);
	_mav_put_uint8_t(buf, 34, orbit_direction);
	_mav_put_uint8_t(buf, 35, current);
	_mav_put_uint8_t(buf, 36, autocontinue);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WAYPOINT_LEN);
#else
	mavlink_waypoint_t packet;
	packet.orbit = orbit;
	packet.param1 = param1;
	packet.param2 = param2;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.yaw = yaw;
	packet.seq = seq;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.frame = frame;
	packet.action = action;
	packet.orbit_direction = orbit_direction;
	packet.current = current;
	packet.autocontinue = autocontinue;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WAYPOINT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_WAYPOINT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WAYPOINT_LEN, MAVLINK_MSG_ID_WAYPOINT_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WAYPOINT_LEN);
#endif
}

/**
 * @brief Encode a waypoint struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param waypoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_waypoint_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_waypoint_t* waypoint)
{
	return mavlink_msg_waypoint_pack(system_id, component_id, msg, waypoint->target_system, waypoint->target_component, waypoint->seq, waypoint->frame, waypoint->action, waypoint->orbit, waypoint->orbit_direction, waypoint->param1, waypoint->param2, waypoint->current, waypoint->x, waypoint->y, waypoint->z, waypoint->yaw, waypoint->autocontinue);
}

/**
 * @brief Encode a waypoint struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param waypoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_waypoint_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_waypoint_t* waypoint)
{
	return mavlink_msg_waypoint_pack_chan(system_id, component_id, chan, msg, waypoint->target_system, waypoint->target_component, waypoint->seq, waypoint->frame, waypoint->action, waypoint->orbit, waypoint->orbit_direction, waypoint->param1, waypoint->param2, waypoint->current, waypoint->x, waypoint->y, waypoint->z, waypoint->yaw, waypoint->autocontinue);
}

/**
 * @brief Send a waypoint message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param seq Sequence
 * @param frame The coordinate system of the waypoint. see MAV_FRAME in mavlink_types.h
 * @param action The scheduled action for the waypoint. see MAV_ACTION in mavlink_types.h
 * @param orbit Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
 * @param orbit_direction Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
 * @param param1 For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
 * @param param2 For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
 * @param current false:0, true:1
 * @param x local: x position, global: longitude
 * @param y y position: global: latitude
 * @param z z position: global: altitude
 * @param yaw yaw orientation in radians, 0 = NORTH
 * @param autocontinue autocontinue to next wp
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_waypoint_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t frame, uint8_t action, float orbit, uint8_t orbit_direction, float param1, float param2, uint8_t current, float x, float y, float z, float yaw, uint8_t autocontinue)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_WAYPOINT_LEN];
	_mav_put_float(buf, 0, orbit);
	_mav_put_float(buf, 4, param1);
	_mav_put_float(buf, 8, param2);
	_mav_put_float(buf, 12, x);
	_mav_put_float(buf, 16, y);
	_mav_put_float(buf, 20, z);
	_mav_put_float(buf, 24, yaw);
	_mav_put_uint16_t(buf, 28, seq);
	_mav_put_uint8_t(buf, 30, target_system);
	_mav_put_uint8_t(buf, 31, target_component);
	_mav_put_uint8_t(buf, 32, frame);
	_mav_put_uint8_t(buf, 33, action);
	_mav_put_uint8_t(buf, 34, orbit_direction);
	_mav_put_uint8_t(buf, 35, current);
	_mav_put_uint8_t(buf, 36, autocontinue);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT, buf, MAVLINK_MSG_ID_WAYPOINT_LEN, MAVLINK_MSG_ID_WAYPOINT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT, buf, MAVLINK_MSG_ID_WAYPOINT_LEN);
#endif
#else
	mavlink_waypoint_t packet;
	packet.orbit = orbit;
	packet.param1 = param1;
	packet.param2 = param2;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.yaw = yaw;
	packet.seq = seq;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.frame = frame;
	packet.action = action;
	packet.orbit_direction = orbit_direction;
	packet.current = current;
	packet.autocontinue = autocontinue;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT, (const char *)&packet, MAVLINK_MSG_ID_WAYPOINT_LEN, MAVLINK_MSG_ID_WAYPOINT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT, (const char *)&packet, MAVLINK_MSG_ID_WAYPOINT_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_WAYPOINT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_waypoint_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t frame, uint8_t action, float orbit, uint8_t orbit_direction, float param1, float param2, uint8_t current, float x, float y, float z, float yaw, uint8_t autocontinue)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, orbit);
	_mav_put_float(buf, 4, param1);
	_mav_put_float(buf, 8, param2);
	_mav_put_float(buf, 12, x);
	_mav_put_float(buf, 16, y);
	_mav_put_float(buf, 20, z);
	_mav_put_float(buf, 24, yaw);
	_mav_put_uint16_t(buf, 28, seq);
	_mav_put_uint8_t(buf, 30, target_system);
	_mav_put_uint8_t(buf, 31, target_component);
	_mav_put_uint8_t(buf, 32, frame);
	_mav_put_uint8_t(buf, 33, action);
	_mav_put_uint8_t(buf, 34, orbit_direction);
	_mav_put_uint8_t(buf, 35, current);
	_mav_put_uint8_t(buf, 36, autocontinue);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT, buf, MAVLINK_MSG_ID_WAYPOINT_LEN, MAVLINK_MSG_ID_WAYPOINT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT, buf, MAVLINK_MSG_ID_WAYPOINT_LEN);
#endif
#else
	mavlink_waypoint_t *packet = (mavlink_waypoint_t *)msgbuf;
	packet->orbit = orbit;
	packet->param1 = param1;
	packet->param2 = param2;
	packet->x = x;
	packet->y = y;
	packet->z = z;
	packet->yaw = yaw;
	packet->seq = seq;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->frame = frame;
	packet->action = action;
	packet->orbit_direction = orbit_direction;
	packet->current = current;
	packet->autocontinue = autocontinue;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT, (const char *)packet, MAVLINK_MSG_ID_WAYPOINT_LEN, MAVLINK_MSG_ID_WAYPOINT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINT, (const char *)packet, MAVLINK_MSG_ID_WAYPOINT_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE WAYPOINT UNPACKING


/**
 * @brief Get field target_system from waypoint message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_waypoint_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field target_component from waypoint message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_waypoint_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  31);
}

/**
 * @brief Get field seq from waypoint message
 *
 * @return Sequence
 */
static inline uint16_t mavlink_msg_waypoint_get_seq(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field frame from waypoint message
 *
 * @return The coordinate system of the waypoint. see MAV_FRAME in mavlink_types.h
 */
static inline uint8_t mavlink_msg_waypoint_get_frame(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field action from waypoint message
 *
 * @return The scheduled action for the waypoint. see MAV_ACTION in mavlink_types.h
 */
static inline uint8_t mavlink_msg_waypoint_get_action(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  33);
}

/**
 * @brief Get field orbit from waypoint message
 *
 * @return Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
 */
static inline float mavlink_msg_waypoint_get_orbit(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field orbit_direction from waypoint message
 *
 * @return Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
 */
static inline uint8_t mavlink_msg_waypoint_get_orbit_direction(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Get field param1 from waypoint message
 *
 * @return For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
 */
static inline float mavlink_msg_waypoint_get_param1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param2 from waypoint message
 *
 * @return For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
 */
static inline float mavlink_msg_waypoint_get_param2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field current from waypoint message
 *
 * @return false:0, true:1
 */
static inline uint8_t mavlink_msg_waypoint_get_current(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  35);
}

/**
 * @brief Get field x from waypoint message
 *
 * @return local: x position, global: longitude
 */
static inline float mavlink_msg_waypoint_get_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field y from waypoint message
 *
 * @return y position: global: latitude
 */
static inline float mavlink_msg_waypoint_get_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field z from waypoint message
 *
 * @return z position: global: altitude
 */
static inline float mavlink_msg_waypoint_get_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field yaw from waypoint message
 *
 * @return yaw orientation in radians, 0 = NORTH
 */
static inline float mavlink_msg_waypoint_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field autocontinue from waypoint message
 *
 * @return autocontinue to next wp
 */
static inline uint8_t mavlink_msg_waypoint_get_autocontinue(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Decode a waypoint message into a struct
 *
 * @param msg The message to decode
 * @param waypoint C-struct to decode the message contents into
 */
static inline void mavlink_msg_waypoint_decode(const mavlink_message_t* msg, mavlink_waypoint_t* waypoint)
{
#if MAVLINK_NEED_BYTE_SWAP
	waypoint->orbit = mavlink_msg_waypoint_get_orbit(msg);
	waypoint->param1 = mavlink_msg_waypoint_get_param1(msg);
	waypoint->param2 = mavlink_msg_waypoint_get_param2(msg);
	waypoint->x = mavlink_msg_waypoint_get_x(msg);
	waypoint->y = mavlink_msg_waypoint_get_y(msg);
	waypoint->z = mavlink_msg_waypoint_get_z(msg);
	waypoint->yaw = mavlink_msg_waypoint_get_yaw(msg);
	waypoint->seq = mavlink_msg_waypoint_get_seq(msg);
	waypoint->target_system = mavlink_msg_waypoint_get_target_system(msg);
	waypoint->target_component = mavlink_msg_waypoint_get_target_component(msg);
	waypoint->frame = mavlink_msg_waypoint_get_frame(msg);
	waypoint->action = mavlink_msg_waypoint_get_action(msg);
	waypoint->orbit_direction = mavlink_msg_waypoint_get_orbit_direction(msg);
	waypoint->current = mavlink_msg_waypoint_get_current(msg);
	waypoint->autocontinue = mavlink_msg_waypoint_get_autocontinue(msg);
#else
	memcpy(waypoint, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_WAYPOINT_LEN);
#endif
}
