GraphIds = {}
local GraphIdsMT = { __index = GraphIds }

function GraphIds:new( space, givenIds )
	self = {}
	self.model = space.universe.model
	
	self.objectIdMap = {}
	self.idObjectMap = {}
	self.currentId = 0
	setmetatable( self, GraphIdsMT )
	if givenIds then
		self:giveExternalIds( space.rootObject, givenIds )
	else
		self:objectId( space.rootObject )
	end
	return self;
end

function GraphIds:insertInMap( service, givenId )
	if givenId == nil then
		--generated
		self.currentId = self.currentId + 1
		givenId = self.currentId
	else
		if givenId > self.currentId then
			self.currentId = givenId 
		end
	end
	self.objectIdMap[service] = givenId
	self.idObjectMap[givenId] = service
end

function GraphIds:hasId( service )
	return ( self.objectIdMap[service] ~= nil )
end

function GraphIds:getId( service )
	local id = self.objectIdMap[service]
	return id
end

function GraphIds:getService( id )
	return self.idObjectMap[id]
end

function GraphIds:removeObject( object )
	if self:hasId( object ) then
		local ports = self.model:getPorts( object.component )
		
		for i, port in ipairs( ports ) do
			local service = object[port.name]
			if service ~= nil then
				self.objectIdMap[ service ] = nil
			end
		end
		self.objectIdMap[object] = nil
	end
end

local function generateId( self, item, referenceObject )
	if not self:hasId( item ) then
		self:insertInMap( item )
	end
end

local function giveId( self, item, givenIds )
	if not self:hasId( item ) then
		local givenId = table.remove( givenIds, 1 )
		self:insertInMap( item, givenId )
	end
	return false
end

local idList = {}
local marked = {}

local function getId( self, item )
	if self:hasId( item ) and not marked[item] then
		idList[ #idList + 1 ] = self:getId( item )
		marked[item] = true
	end
	return false
end

function GraphIds:getOrderedIds( object, givenIds )
	idList = {}
	marked = {}
	self:genericGraphWalk( object, getId, givenIds )
	return idList
end

function GraphIds:giveExternalIds( object, givenIds )
	self:genericGraphWalk( object, giveId, givenIds )
end

function GraphIds:shallowObjectId( object, externalId )
	self:insertInMap( object, externalId )
	local ports = self.model:getPorts( object.component )
			
	for i, port in ipairs( ports ) do
		local service = object[port.name]
		if service ~= nil then
			self:insertInMap( service )
		end
	end
end

function GraphIds:objectId( object )
	self:genericGraphWalk( object, generateId )
end

function GraphIds:genericGraphWalk( item, callback, ... )
	local stop = false
	local arg = {...}
	stop = callback( self, item, ... )
	
	if stop then
		return
	end
	if item.component ~= nil then
		-- is an object
		local ports = self.model:getPorts( item.component )
			
		for i, port in ipairs( ports ) do
			local service = item[port.name]
			if service ~= nil then
				self:genericGraphWalk( service, callback, ... )
			end
		end
	elseif item.interface ~= nil then
		--is an service
		local service = item
		local fields = self.model:getFields( service.interface )
		local kind
		local fieldName
		for i, field in ipairs( fields ) do
			kind = field.type.kind
			fieldName = field.name
			if kind == 'TK_INTERFACE' then
				if service[fieldName] ~= nil then
					self:genericGraphWalk( service[fieldName].provider, callback, ... )
				end
			elseif kind == 'TK_ARRAY' and field.type.elementType.kind == 'TK_INTERFACE' then
				local refs = service[fieldName]
				for i, ref in ipairs( refs ) do
					self:genericGraphWalk( ref.provider, callback, ... )
				end
			end
		end	
	end
end

return GraphIds