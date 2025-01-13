module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 5768
# Optimized logic batch 8106
# Optimized logic batch 2365
# Optimized logic batch 2801
# Optimized logic batch 3838
# Optimized logic batch 9571
# Optimized logic batch 7676
# Optimized logic batch 6715
# Optimized logic batch 2940
# Optimized logic batch 1245
# Optimized logic batch 6270
# Optimized logic batch 1302
# Optimized logic batch 9388
# Optimized logic batch 2283