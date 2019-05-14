#pragma once

/**
 * @brief Initializes the user program
 * 
 * @param int argc Number of arguments passed throught the command line
 * @param char *argv[] Arguments passed throught the command line
 * @param tlv_request_t *tlv TLV struct with the request for the server
 * @param req_create_account_t *createAccount Struct used for the request to the server
 * @param req_transfer_t *transfer Struct used for the request to the server
 * @param req_header_t *header Struct used for the request to the server
 * @param req_value_t *value Struct used for the request to the server
 */
void init(int argc, char *argv[], tlv_request_t *tlv, req_create_account_t *createAccount, req_transfer_t *transfer, req_header_t *header, req_value_t *value);

/**
 * @brief Fills the necessary structs according to the respective operation
 * 
 * @param int op Operation needed to complete
 * @param char *argList Argument List used for the user operation
 * @param req_create_account_t *createAccount Struct used for the request to the server
 * @param req_transfer_t *transfer Struct used for the request to the server
 * @param req_value_t *value Struct used for the request to the server
 */
void fillOperationInfo(int op, char *argList, req_create_account_t *createAccount, req_transfer_t *transfer, req_value_t *value);

/**
 * @brief Fills the request header
 * 
 * @param char *argv[] Arguments passed throught the command line
 * @param req_header_t *header Struct used for the request to the server
 * @param req_value_t *value Struct used for the request to the server
 */
void fillHeader(char *argv[], req_header_t *header, req_value_t *value);

/**
 * @brief Generates the user FIFO path based on its PID
 * 
 * @param tlv_request_t tlv Struct with the request information
 * @return char* FIFO path
 */
char *getFIFOname();

/**
 * @brief Reads the FIFO from the server with the reply
 * 
 * @param tlv_request_t *tlv Struct with the request for the server
 */
void writeRequest(tlv_request_t *tlv);

/**
 * @brief Reads the FIFO from the server with the reply
 * 
 * @param tlv_reply_t reply Struct with the reply from the server
 * @param char* fifo FIFO path of the userFifo
 */
void readReply(tlv_reply_t reply, char *fifo);