#pragma once
#include "stdafx.h"
#include "Constants.h"
#include "utils.h"
#include "CompareStringsLessThanIgnoreCase.h"
#include "CompareStringsEqualIgnoreCase.h"
#include "MillisToTimespanConverter.h"
#include "json_utils.h"
#include "DateTimeOffset.h"
#include "RavenException.h"
#include "AllTopologyNodesDownException.h"
#include "AttachmentDoesNotExistException.h"
#include "SecurityException.h"
#include "AuthenticationException.h"
#include "AuthorizationException.h"
#include "BadRequestException.h"
#include "BadResponseException.h"
#include "BulkInsertAbortedException.h"
#include "BulkInsertProtocolViolationException.h"
#include "CertificateNameMismatchException.h"
#include "ChangeProcessingException.h"
#include "ClientVersionMismatchException.h"
#include "CommandExecutionException.h"
#include "CompilationException.h"
#include "ConflictException.h"
#include "ConcurrencyException.h"
#include "CounterOverflowException.h"
#include "CurlSListHolder.h"
#include "CurlHandlesHolder.h"
#include "CurlResponse.h"
#include "CurlException.h"
#include "DatabaseConcurrentLoadTimeoutException.h"
#include "DatabaseDisabledException.h"
#include "DatabaseDoesNotExistException.h"
#include "DatabaseLoadFailureException.h"
#include "DatabaseLoadTimeoutException.h"
#include "DatabaseNotRelevantException.h"
#include "DatabaseSchemaErrorException.h"
#include "DocumentConflictException.h"
#include "DocumentDoesNotExistException.h"
#include "ExceptionDispatcher.h"
#include "IndexAlreadyExistException.h"
#include "IndexCompilationException.h"
#include "IndexCreationException.h"
#include "IndexDeletionException.h"
#include "IndexDoesNotExistException.h"
#include "IndexInvalidException.h"
#include "InvalidQueryException.h"
#include "JavaScriptException.h"
#include "JavaScriptParseException.h"
#include "LicenseActivationException.h"
#include "NodeIsPassiveException.h"
#include "NoLeaderException.h"
#include "NonUniqueObjectException.h"
#include "OperationCancelledException.h"
#include "OperationExceptionResult.h"
#include "RevisionsDisabledException.h"
#include "RouteNotFoundException.h"
#include "ServerLoadFailureException.h"
#include "SubscriptionException.h"
#include "SubscriberErrorException.h"
#include "SubscriptionChangeVectorUpdateConcurrencyException.h"
#include "SubscriptionClosedException.h"
#include "SubscriptionDoesNotBelongToNodeException.h"
#include "SubscriptionDoesNotExistException.h"
#include "SubscriptionInUseException.h"
#include "SubscriptionInvalidStateException.h"
#include "TimeoutException.h"
#include "UnsuccessfulRequestException.h"
#include "Parameters.h"
#include "Size.h"
#include "GetCppClassName.h"
#include "HttpStatus.h"
#include "ServerNode.h"
#include "ResponseDisposeHandling.h"
#include "HttpCacheItem.h"
#include "HttpCache.h"
#include "HttpExtensions.h"
#include "RavenCommand.h"
#include "Topology.h"
#include "CertificateDetails.h"
#include "ReadBalanceBehavior.h"
#include "ClientConfiguration.h"
#include "EntityIdHelper.h"
#include "DocumentConventions.h"
#include "IMaintenanceOperation.h"
#include "IndexState.h"
#include "IndexLockMode.h"
#include "IndexPriority.h"
#include "IndexType.h"
#include "IndexInformation.h"
#include "DatabaseStatistics.h"
#include "GetStatisticsOperation.h"
#include "IExecutorService.h"
#include "TasksScheduler.h"
#include "Timer.h"
#include "NodeStatus.h"
#include "CurrentIndexAndNode.h"
#include "NodeSelector.h"
#include "SessionInfo.h"
#include "RequestExecutor.h"
#include "TransactionMode.h"
#include "BatchCommandResult.h"
#include "CommandType.h"
#include "CommandDataBase.h"
#include "ReplicationBatchOptions.h"
#include "BatchOptions.h"
#include "PutAttachmentCommandData.h"
#include "PutAttachmentCommandHelper.h"
#include "BatchCommand.h"
#include "CopyAttachmentCommandData.h"
#include "DeleteAttachmentCommandData.h"
#include "MoveAttachmentCommandData.h"
#include "DeleteCommandData.h"
#include "VoidRavenCommand.h"
#include "DeleteDocumentCommand.h"
#include "ClusterTopology.h"
#include "ClusterTopologyResponse.h"
#include "GetClusterTopologyCommand.h"
#include "GetDatabaseTopologyCommand.h"
#include "GetDocumentsResult.h"
#include "GetDocumentsCommand.h"
#include "GetNextOperationIdCommand.h"
#include "TcpConnectionInfo.h"
#include "GetTcpInfoCommand.h"
#include "HeadAttachmentCommand.h"
#include "HeadDocumentCommand.h"
#include "HiLoReturnCommand.h"
#include "GetResponse.h"
#include "GetRequest.h"
#include "MultiGetCommand.h"
#include "HiLoResult.h"
#include "NextHiLoCommand.h"
#include "PatchRequest.h"
#include "PatchCommandData.h"
#include "BatchPatchCommandData.h"
#include "PutCommandData.h"
#include "PutResult.h"
#include "PutDocumentCommand.h"
#include "QueryTimings.h"
#include "QueryResultBase.h"
#include "GenericQueryResult.h"
#include "QueryResult.h"
#include "IndexQueryBase.h"
#include "IndexQuery.h"
#include "QueryCommand.h"
#include "IServerOperation.h"
#include "DatabasePromotionStatus.h"
#include "LeaderStamp.h"
#include "DatabaseTopology.h"
#include "DatabasePutResult.h"
#include "AddDatabaseNodeOperation.h"
#include "BatchOperation.h"
#include "OperationIdResult.h"
#include "CompactSettings.h"
#include "CompactDatabaseOperation.h"
#include "ScriptResolver.h"
#include "ConflictSolver.h"
#include "IndexConfiguration.h"
#include "FieldStorage.h"
#include "FieldIndexing.h"
#include "FieldTermVector.h"
#include "SpatialFieldType.h"
#include "SpatialSearchStrategy.h"
#include "SpatialUnits.h"
#include "SpatialOptions.h"
#include "IndexFieldOptions.h"
#include "IndexDefinition.h"
#include "DatabaseRecord.h"
#include "CreateDatabaseOperation.h"
#include "IDisposalNotification.h"
#include "IDocumentStore.h"
#include "IOperation.h"
#include "IVoidOperation.h"
#include "QueryOperationOptions.h"
#include "DeleteByQueryOperation.h"
#include "DeleteAttachmentOperation.h"
#include "DeleteDatabaseResult.h"
#include "DeleteDatabasesOperation.h"
#include "IVoidMaintenanceOperation.h"
#include "DeleteIndexOperation.h"
#include "DisableIndexOperation.h"
#include "EnableIndexOperation.h"
#include "AttachmentName.h"
#include "AttachmentDetails.h"
#include "AttachmentType.h"
#include "AttachmentResult.h"
#include "GetAttachmentOperation.h"
#include "BuildNumber.h"
#include "GetBuildNumberOperation.h"
#include "GetClientConfigurationOperation.h"
#include "CollectionStatistics.h"
#include "GetCollectionStatisticsOperation.h"
#include "GetDatabaseNamesOperation.h"
#include "GetDatabaseRecordOperation.h"
#include "DetailedDatabaseStatistics.h"
#include "GetDetailedStatisticsOperation.h"
#include "IndexingError.h"
#include "IndexErrors.h"
#include "GetIndexErrorsOperation.h"
#include "GetIndexesOperation.h"
#include "IndexRunningStatus.h"
#include "IndexStats.h"
#include "GetIndexesStatisticsOperation.h"
#include "IndexingStatus.h"
#include "GetIndexingStatusOperation.h"
#include "GetIndexNamesOperation.h"
#include "GetIndexOperation.h"
#include "GetIndexStatisticsOperation.h"
#include "GetOperationStateOperation.h"
#include "GetServerWideClientConfigurationOperation.h"
#include "GetServerWideOperationStateOperation.h"
#include "TermsQueryResult.h"
#include "GetTermsOperation.h"
#include "ILazyOperation.h"
#include "IndexHasChangedOperation.h"
#include "IVoidServerOperation.h"
#include "DocumentsChanges.h"
#include "ConcurrencyCheckMode.h"
#include "IMetadataDictionary.h"
#include "DocumentInfo.h"
#include "JsonOperation.h"
#include "DocumentsById.h"
#include "EntityToJson.h"
#include "PatchStatus.h"
#include "PatchResult.h"
#include "PatchOperation.h"
#include "Operation.h"
#include "OperationExecutor.h"
#include "GenerateEntityIdOnTheClient.h"
#include "EventArgs.h"
#include "EventHandler.h"
#include "InMemoryDocumentSessionOperations.h"
#include "DocumentsByIdsMap.h"
#include "LoadOperation.h"
#include "LazyLoadOperation.h"
#include "QueryToken.h"
#include "FieldsToFetchToken.h"
#include "SimpleStopWatch.h"
#include "QueryOperation.h"
#include "IndexQueryContent.h"
#include "LazyQueryOperation.h"
#include "LazyStartsWithOperation.h"
#include "LoadStartingWithOperation.h"
#include "ClusterRequestExecutor.h"
#include "DocumentStoreBase.h"
#include "DocumentStore.h"
#include "ServerOperationExecutor.h"
#include "MaintenanceOperationExecutor.h"
#include "MultiGetOperation.h"
#include "PatchByQueryOperation.h"
#include "PromoteDatabaseNodeOperation.h"
#include "PutAttachmentOperation.h"
#include "PutClientConfigurationOperation.h"
#include "PutIndexResult.h"
#include "PutIndexesOperation.h"
#include "PutServerWideClientConfigurationOperation.h"
#include "QueryOperator.h"
#include "ReorderDatabaseMembersOperation.h"
#include "ResetIndexOperation.h"
#include "SearchOperator.h"
#include "ServerWideOperation.h"
#include "SessionOperationExecutor.h"
#include "SetIndexesLockOperation.h"
#include "SetIndexesPriorityOperation.h"
#include "StartIndexingOperationh.h"
#include "StartIndexOperation.h"
#include "StopIndexingOperation.h"
#include "StopIndexOperation.h"
#include "DisableDatabaseToggleResult.h"
#include "ToggleDatabasesStateOperation.h"
#include "WhereOperator.h"
#include "CloseSubclauseToken.h"
#include "CounterIncludesToken.h"
#include "DeclareToken.h"
#include "DistinctToken.h"
#include "ExplanationToken.h"
#include "FacetToken.h"
#include "FromToken.h"
#include "GroupByCountToken.h"
#include "GroupByKeyToken.h"
#include "GroupBySumToken.h"
#include "GroupByMethod.h"
#include "GroupByToken.h"
#include "HighlightingToken.h"
#include "IntersectMarkerToken.h"
#include "LoadToken.h"
#include "ShapeToken.h"
#include "WhereToken.h"
#include "MoreLikeThisToken.h"
#include "NegateToken.h"
#include "OpenSubclauseToken.h"
#include "OrderingType.h"
#include "OrderByToken.h"
#include "QueryOperatorToken.h"
#include "SuggestToken.h"
#include "TimingsToken.h"
#include "TrueToken.h"
#include "AdvancedSessionExtentionBase.h"
#include "Lazy.h"
#include "QueryStatistics.h"
#include "GroupBy.h"
#include "MoreLikeThisOptions.h"
#include "MoreLikeThisScope.h"
#include "QueryFieldUtil.h"
#include "WhereParams.h"
#include "MethodCall.h"
#include "CmpXchg.h"
#include "Highlightings.h"
#include "QueryHighlightings.h"
#include "Explanations.h"
#include "DocumentQueryHelper.h"
#include "QueryData.h"
#include "HighlightingOptions.h"
#include "SpatialRelation.h"
#include "DynamicSpatialField.h"
#include "SpatialCriteria.h"
#include "StringDistanceTypes.h"
#include "SuggestionSortMode.h"
#include "SuggestionOptions.h"
#include "SuggestionBase.h"
#include "SuggestionWithTerm.h"
#include "SuggestionWithTerms.h"
#include "ExplanationOptions.h"
#include "EventHelper.h"
#include "IncludeBuilderBase.h"
#include "AbstractDocumentQuery.h"
#include "IDocumentQueryBaseSingle.h"
#include "IQueryBase.h"
#include "SpatialOptionsFactory.h"
#include "MoreLikeThisBase.h"
#include "SpatialCriteriaFactory.h"
#include "IFilterDocumentQueryBase.h"
#include "IQueryIncludeBuilder.h"
#include "QueryIncludeBuilder.h"
#include "IDocumentQueryBase.h"
#include "IEnumerableQuery.h"
#include "IDocumentQuery.h"
#include "MoreLikeThisUsingDocument.h"
#include "GroupByField.h"
#include "IGroupByDocumentQuery.h"
#include "GroupByDocumentQuery.h"
#include "DocumentQuery.h"
#include "IRawDocumentQuery.h"
#include "RawDocumentQuery.h"
#include "JavaScriptArray.h"
#include "ResponseTimeInformation.h"
#include "Query.h"
#include "AbstractIndexCreationTaskBase.h"
#include "AbstractGenericIndexCreationTask.h"
#include "AbstractIndexCreationTask.h"
#include "IAttachmentsSessionOperationsBase.h"
#include "IAttachmentsSessionOperations.h"
#include "DocumentSessionImpl.h"
#include "EagerSessionOperations.h"
#include "AdvancedSessionOperations.h"
#include "MultiLoaderWithInclude.h"
#include "LoaderWithInclude.h"
#include "DocumentSession.h"
#include "DocumentSessionAttachmentsBase.h"
#include "DocumentSessionAttachments.h"
#include "LazyMultiLoaderWithInclude.h"
#include "LazyLoaderWithInclude.h"
#include "LazySessionOperationsImpl.h"
#include "LazySessionOperations.h"
#include "SessionCreatedEventArgs.h"
#include "SessionOptions.h"
#include "Inflector.h"
#include "MoreLikeThisUsingAnyDocument.h"
#include "IndexTypeExtensions.h"
#include "AutoSpatialMethodType.h"
#include "AutoSpatialOptions.h"
#include "MetadataAsDictionary.h"
#include "AbstractMultiMapIndexCreationTask.h"
#include "HiLoIdGenerator.h"
#include "MultiTypeHiLoIdGenerator.h"
#include "MultiDatabaseHiLoIdGenerator.h"
#include "AbstractJavaScriptIndexCreationTask.h"
#include "IndexCreation.h"
#include "IndexDefinitionBuilder.h"
#include "WktField.h"
#include "PointField.h"
#include "WktCriteria.h"
#include "CircleCriteria.h"
#include "SpatialRelation.h"
#include "IndexBatchOptions.h"
#include "MoreLikeThisUsingDocumentForDocumentQuery.h"
#include "TasksExecutor.h"
#include "EntityIdHelperUtil.h"