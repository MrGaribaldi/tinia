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
#pragma once

#include <QtScript>
#include <tinia/model/ExposedModel.hpp>
#include <tinia/qtcontroller/scripting/ExposedModel.hpp>
#include <QMouseEvent>

namespace tinia {
namespace qtcontroller {
namespace scripting {

/** Basic EventHandler. Will pass events to the relevant methods in the Script class
 */
class EventHandler
{
public:
    /** Construct the EventHandler.
     *
     * @param scriptClassName the name of the class to constructor and call methods in.
     *                        Must be available in the ScriptEngine before invocation
     * @param model           The associated model.
     */
    EventHandler(const std::string& scriptClassName,
                 std::shared_ptr<tinia::model::ExposedModel> model,
                 QScriptEngine& engine);

    /** Will pass the event to "mouseMoveEvent" in the scriptclass
     */
    void mouseMoveEvent(QMouseEvent* event);

    /** Will pass the event to "mousePressEvent" in the scriptclass
     */
    void mousePressEvent(QMouseEvent* event);

    /** Will pass the event to "mouseReleaseEvent" in the scriptclass
     */
    void mouseReleaseEvent(QMouseEvent* event);

private:
    QScriptEngine& m_engine;
    ExposedModel m_scriptModel;
    std::shared_ptr<tinia::model::ExposedModel> m_model;
    QScriptValue m_scriptHandler;
};

} // namespace scripting
} // namespace qtcontroller
} // namespace tinia

