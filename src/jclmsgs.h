/*******************************************************************************
 * Copyright (c) 2017 IBM.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *    Mike Fulton - initial implementation and documentation
 *******************************************************************************/

#ifndef __JCLMSG__
	#define __JCLMSG__ 1
	
	/*
	 * The JCLScanMsg_T enum and JCLScanMessage must be kept in sync.
	 */
	typedef enum {
		UnreachableCodeError=-2,
		InputEOF=-1,
		NoError=0,
		TooFewArgsSingular=1,
		TooFewArgsPlural=2,
		TooManyArgs=3,
		UnrecognizedOption=4,
		InternalOutOfMemory=5,
		UnableToEstablishEnvironment=6,
		ErrorEstablishingEnvironment=7,
		IssueHelp=8,
		NoArgSpecified=9,
		UnableToOpenInput=10,
		UnableToOpenOutput=11,
		UnableToReopenInput=12,
		UnableToReopenOutput=13,
		InvalidRecordEncountered=14,
	} JCLScanMsg_T;
	
	/*
	 * The JCLScanInfo_T enum and JCLScanInfo must be kept in sync.
	 */
	typedef enum {
		InfoNone=0,

		InfoSyntax01=1,
		InfoSyntax02=2,
		InfoSyntax03=3,
		InfoSyntax04=4,
		InfoSyntax05=5,
		InfoSyntax06=6,
		InfoSyntax07=7,
		InfoSyntax08=8,
		InfoSyntax09=9,
		InfoSyntax10=10,
		InputRecordTruncated=11,
		InfoJCLText=12,
		InfoProcessDDStatement=13,
		InfoProcessExecStatement=14,	
		InfoProcessJobStatement=15,		
		InfoProcessCommentStatement=16,	
		InfoInParameter=17,	
		InfoInString=18,						
		InfoInComment=19,
		InfoStmtDump=20,
	} JCLScanInfo_T;
	
#ifdef DEBUG
	#define FORCE(FAIL_Condition) \
		(getenv(#FAIL_Condition))
#else
	#define FORCE(FAIL_Condition) (0)
#endif
	void printHelp(const char* pgmName);

	void printError(JCLScanMsg_T pfm, ...);
	void printInfo(JCLScanInfo_T pim, ...);
#endif	