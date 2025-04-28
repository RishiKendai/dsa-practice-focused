class EventEmitter {

    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */

    _eventCallbacksMap = new Map();
    _subscribersCB = new Map();
    _index = 0;
    subscribe(eventName, callback) {
        const subscriberID = this._index++;
        if (this._eventCallbacksMap.has(eventName)) {
            const subscriberIDs = this._eventCallbacksMap.get(eventName);
            subscriberIDs.push(subscriberID);
            this._eventCallbacksMap.set(eventName, subscriberIDs);
        } else {
            this._eventCallbacksMap.set(eventName, [subscriberID]);
        }
        this._subscribersCB.set(subscriberID, callback);

        return {
            unsubscribe: () => {
                const cbs = this._eventCallbacksMap.get(eventName);
                const filteredCbs = cbs.filter((sid) => {
                    return sid !== subscriberID;
                });
                this._subscribersCB.delete(subscriberID);
                if (filteredCbs.length === 0) this._eventCallbacksMap.delete(eventName);
                this._eventCallbacksMap.set(eventName, filteredCbs);
                return undefined;
            }
        };
    }

    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        if (!this._eventCallbacksMap.has(eventName)) return [];
        const sID = this._eventCallbacksMap.get(eventName);
        const result = sID.map((sid) => {
            return this._subscribersCB.get(sid)(...args);
        });
        return result;
    }
}


// const emitter = new EventEmitter();

// // Subscribe to the onClick event with onClickCallback
// function onClickCallback() { return 99; }
// const sub = emitter.subscribe('onClick', onClickCallback);

// console.log(emitter.emit('onClick')); // [99]
// sub.unsubscribe(); // undefined
// console.log(emitter.emit('onClick')); // []

// const emitter = new EventEmitter();
// const sub = emitter.subscribe("firstEvent", (...args) => args.join(','));
// console.log(emitter.emit("firstEvent", [1, 2, 3])); // ["1,2,3"]
// sub.unsubscribe(); // undefined
// console.log(emitter.emit("firstEvent", [4, 5, 6])); // [], there are no subscriptions

// const emitter = new EventEmitter();
// const sub1 = emitter.subscribe("firstEvent", x => x + 1);
// const sub2 = emitter.subscribe("firstEvent", x => x + 2);
// sub1.unsubscribe(); // undefined
// console.log(emitter.emit("firstEvent", [5])); // [7]



// const emitter = new EventEmitter();
// const sub1 = emitter.subscribe("firstEvent", x => x + 1);
// const sub2 = emitter.subscribe("firstEvent", x => x + 2);
// const sub3 = emitter.subscribe("firstEvent", x => x + 3);
// sub2.unsubscribe(); // undefined
// sub3.unsubscribe(); // undefined
// console.log(emitter.emit("firstEvent", [5])); // [6]