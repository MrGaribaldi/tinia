/* Copyright STIFTELSEN SINTEF 2012
 * 
 * This file is part of the Tinia Framework.
 * 
 * The Tinia Framework is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * The Tinia Framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with the Tinia Framework.  If not, see <http://www.gnu.org/licenses/>.
 */

dojo.provide("model.gui.GUILayout");

dojo.declare("model.gui.Element", null, {
    constructor: function() {
        
        this._visibilityKey = null;
        this._enabledKey = null;
        this._visibilityKeyInverted = false;
        this._enabledKeyInverted = false;
    },
    
    setEnabledKey : function(key) {
        this._enabledKey = key;
    },
    
    setEnabledKeyInverted: function(key) {
        this._enabledKeyInverted = key
    },
    
    setVisibilityKey: function(key) {
        this._visibilityKey = key;
    },
    
    setVisibilityKeyInverted: function(key) {
        this._visibilityKeyInverted = key;
    },
    enabledKey : function() {
        return this._enabledKey;
    },
    
    enabledKeyInverted: function() {
        return this._enabledKeyInverted;
    },
    
    visibilityKey: function() {
        return this._visibilityKey;
    },
    
    visibilityKeyInverted: function() {
        return this._visibilityKeyInverted;
    },
    
    type: function() {
        throw "Unknown type.";
    }
});

dojo.declare("model.gui.HorizontalSpace", model.gui.Element, {
    type: function() { 
        return "HorizontalSpace";
    }
});
dojo.declare("model.gui.HorizontalExpandingSpace", model.gui.Element, {
    type: function() {
        return "HorizontalExpandingSpace";
    }
});
dojo.declare("model.gui.VerticalSpace", model.gui.Element, {
    type: function() {
        return "VerticalSpace";
    }
});
dojo.declare("model.gui.VerticalExpandingSpace", model.gui.Element, {
    type: function() {
        return "VerticalExpandingSpace";
    }
});

dojo.declare("model.gui.Container0D", model.gui.Element, {
    constructor: function() {
        this._child = null;
    },
    
    setChild: function(child) {
        this._child = child;
    },
    
    addChild: function(child) {
        this.setChild(child);
    },
    
    child: function() {
        return this._child;
    }
});

dojo.declare("model.gui.Container1D", model.gui.Element, {
    constructor: function() {
        this._children = [];
    },
    
    addChild : function(child) {
        this._children[this._children.length] = child;
    },
    
    child: function(index) {
        if(index >= this._children.length) {
            throw "Trying to access child at index " + index 
                + " but the container only has " + this._children.length + " children.";
        }
        return this._children[index];
    },
    
    length: function() {
        return this._children.length;
    }
    
});

dojo.declare("model.gui.Container2D", model.gui.Element, {
    constructor: function() {
        this._children = [];
        this._maxRow = 0;
        this._maxCol = 0;
    },
    
    setChild : function(row, col, child) {
        if(!this._children[row]) {
            this._children[row] = [];
            this._resizeCol();
        }
        if(row > this._maxRow) {
            this._maxRow = row;
            this._resizeRow();
            this._resizeCol();
        }
        if(col > this._maxCol) {
            this._maxCol = col;
            this._resizeCol();
        }
        this._children[row][col] = child;
    },
    
    child: function(row, col) {
        if(row >= this._children.length || col >= this._children[row].length) {
            throw "Trying to access child at index (" + row + ", " + col + ") but no such index exists.";
        }
        return this._children[row][col];
    },
    
    height: function() {
        return this._maxRow+1;
    },
    
    
    width: function() {
        return this._maxCol+1;
    },
    
    _resizeRow: function() {
        for(var i = 0; i < this._maxRow + 1; i++) {
            if(!this._children[i]) {
                this._children[i] = [];
            }
        }
    },
    
    
    _resizeCol: function() {
        for(var i = 0; i < this._maxRow + 1; i++) {
            for(var j = this._children[i].length; j < this._maxCol+1; j++) {
                this._children[i][j] = null;
            }
        }
    }
    
});

dojo.declare("model.gui.TabLayout", model.gui.Container1D,
{
    constructor: function() {
    },
    
    type: function() {
        return "TabLayout";
    },
    
    addChild: function(child) {
        if(child.type() != "Tab") {
            throw "Trying to add " + child.type() + " to a TabLayout.";
        }
        this.inherited(arguments);
    }
});

dojo.declare("model.gui.Tab", model.gui.Container0D, {
    constructor: function(key, showValue) {
        this._showValue = !!showValue;
        this._key = key;
    },
    
    type: function() {
        return "Tab";
    },
    
    key: function() {
        return this._key;
    },
    
    showValue: function() {
        return this._showValue;
    }
    
});

dojo.declare("model.gui.ElementGroup", model.gui.Container0D, {
    constructor: function(key, showValue) {
        this._showValue = !!showValue;
        this._key = key;
    },
    
    type: function() {
        return "ElementGroup";
    },
    
    key: function() {
        return this._key;
    },
    
    showValue: function() {
        return this._showValue;
    }
    
});

dojo.declare("model.gui.PopupButton", model.gui.Container0D, {
    constructor: function(key, showValue) {
        this._showValue = !!showValue;
        this._key = key;
    },
    
    type: function() {
        return "PopupButton";
    },
    
    key: function() {
        return this._key;
    },
    
    showValue: function() {
        return this._showValue;
    }
    
});


dojo.declare("model.gui.HorizontalLayout", model.gui.Container1D, {

    
    type: function() {
        return "HorizontalLayout";
    }
    
});


dojo.declare("model.gui.VerticalLayout", model.gui.Container1D, {

    
    type: function() {
        return "VerticalLayout";
    }
    
});

dojo.declare("model.gui.KeyValue", model.gui.Element, {
    constructor: function(type, key, showValue) {
                           
        this._key = key;
        if(showValue === undefined) {
            showValue = true;
        }
        this._showValue = !!showValue;
        if(this._legalTypes.indexOf(type) > -1) {
        this._type = type;
        } else {
            var types = ""
            for(var i = 0; i < this._legalTypes.length; i++) {
                types += this._legalTypes[i] + ", ";
            }
            types = types.substring(types.length - 2);
            throw "Type: " + type +" is not a legal type. Possible types are: " 
                + types;
        }
        
    },
        
    key: function() {
        return this._key;
    },
        
    showValue: function() {
        return this._showValue;
    },
    
    type: function() {
        return this._type;
    },
    
    // Private
    _legalTypes : ["SpinBox", "DoubleSpinBox", "VerticalSlider", "TextInput", "Checkbox",
                   "RadioButtons", "ComboBox", "Label", "HorizontalSlider", "Button"]
    
});

dojo.declare("model.gui.ScriptArgument", null, {
    constructor: function(className, params) {
        this._className = className;
        this._params = params;
    },
    
    className : function() {
        return this._className;
    },
    
    params : function() {
        return this._params;
    }
});

dojo.declare("model.gui.Canvas", model.gui.Element, {
    constructor: function(key, renderlistKey, boundingBoxKey, resetViewKey, scripts) {
        this._key = key;
        if(renderlistKey === undefined) {
            renderlistKey = key + "_renderlist";
        }
        this._renderlistKey = renderlistKey;
        
        if(boundingBoxKey === undefined) {
            boundingBoxKey = "boundingbox";
        }
        this._boundingBoxKey = boundingBoxKey;
        
        if(resetViewKey === undefined) {
            resetViewKey = "resetview_" + key;
        }
        this._resetViewKey = resetViewKey;
        
        this._scripts = scripts;
    },
    
    key: function() { 
        return this._key;
    },
    
    renderlistKey: function() {
        return this._renderlistKey;
    },
    
    boundingBoxKey: function() {
        return this._boundingBoxKey;
    },
    
    resetViewKey: function() {
        return this._resetViewKey;
    },
    
    type: function() {
        return "Canvas";
    },
    
    scripts : function() {
        return this._scripts;
    }
});

dojo.declare("model.gui.Grid", model.gui.Container2D, {
    type: function() {
        return "Grid";
    }
});


